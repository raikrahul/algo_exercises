/*20.1-8

Suppose that instead of a linked list, each array entry Adj[u] is a
hash table containing the vertices v for which (u, v) ∈ E, with collisions resolved by chaining.
Under the assumption of uniform independent hashing,
if all edge lookups are equally likely,
what is the expected time to determine whether an edge is in the graph?
What disadvantages does this scheme have? Suggest an alternate data structure
for each edge list that solves these problems.
Does your alternative have disadvantages compared with the hash table?*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>

// Graph class representing a node with adjacent elements stored in a hash table
class Graph
{
private:
    std::unordered_map<char, std::vector<char>> adjacencyLists;

public:
    // Function to add an edge between two nodes
    void addEdge(char node, char adjacentNode)
    {
        adjacencyLists[node].push_back(adjacentNode);
    }

    // Function to retrieve adjacent elements of a node
    std::vector<char> getAdjacentElements(char node)
    {
        return adjacencyLists[node];
    }

    // THE FUNCTION AND BELOW DEPEND UPON THE LOAD FACTOR OF THE GRAPH 
    // THE EXPECTED LOOKUP FOR ANY NODE, GIVEN LOOKUP OF ALL NODES IS EQUALLY 
    // LIKELY IS O(1 + load factor)
    // think of the case when all the neighbors of a node hash to the same 
    // bucket in the hash table for that node 
    // then we has to lookup into the linkedlist of size of the degree of the verted 
    // plus one has to lookup 

    // Function to retrieve all adjacency lists in the graph
    std::unordered_map<char, std::vector<char>> getAdjacencyLists()
    {
        return adjacencyLists;
    }
};

// Function to perform edge lookup and calculate expected time for a given node
void performEdgeLookup(char node, Graph &graph, double &totalLookupTime, int &totalLookups, std::mutex &mtx)
{
    std::vector<char> adjacentElements = graph.getAdjacentElements(node);

    for (char adjacentNode : adjacentElements)
    {
        // Perform lookup for each adjacent element
        double lookupTime = 1.0 / adjacentElements.size();
        std::lock_guard<std::mutex> lock(mtx);
        totalLookupTime += lookupTime;
        totalLookups++;

        std::cout << "Lookup time for edge (" << node << " -> " << adjacentNode << "): " << lookupTime << std::endl;
    }
}

int main()
{
    // Create a graph
    Graph graph;

    // Add edges to the graph
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('C', 'A');
    graph.addEdge('C', 'D');

    // Perform edge lookup and calculate the expected time using multiple threads and inputs
    double totalLookupTime = 0.0;
    int totalLookups = 0;
    std::mutex mtx;

    std::vector<std::thread> threads;
    std::vector<char> nodes = {'A', 'B', 'C'};

    for (char node : nodes)
    {
        threads.emplace_back([&]()
                             { performEdgeLookup(node, std::ref(graph), std::ref(totalLookupTime), std::ref(totalLookups), std::ref(mtx)); });
    }

    // Wait for all threads to finish
    for (auto &thread : threads)
    {
        thread.join();
    }

    double expectedTime = totalLookupTime / totalLookups;
    std::cout << "Expected time for edge lookup: " << expectedTime << std::endl;

    return 0;
}
