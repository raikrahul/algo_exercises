#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Graph class representing a node with sorted adjacent elements stored in a hash table
class Graph
{
private:
    std::unordered_map<char, std::vector<char>> adjacencyLists;

public:
    // Function to add an edge between two nodes and sort the adjacent elements
    void addEdge(char node, char adjacentNode)
    {
        adjacencyLists[node].push_back(adjacentNode);
        std::sort(adjacencyLists[node].begin(), adjacencyLists[node].end());
        // the lookup here is constant time 
    }

    // Function to retrieve adjacent elements of a node using binary search
    bool hasAdjacentElement(char node, char adjacentNode)
    {
        auto it = std::lower_bound(adjacencyLists[node].begin(), adjacencyLists[node].end(), adjacentNode);
        return (it != adjacencyLists[node].end() && *it == adjacentNode);
    }

    // Function to retrieve all adjacency lists in the graph
    std::unordered_map<char, std::vector<char>> getAdjacencyLists()
    {
        return adjacencyLists;
    }
};

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

    // Perform edge lookup using binary search
    for (auto &adjacencyList : graph.getAdjacencyLists())
    {
        char node = adjacencyList.first;
        std::vector<char> adjacentElements = adjacencyList.second;

        for (char adjacentNode : adjacentElements)
        {
            bool hasNeighbor = graph.hasAdjacentElement(node, adjacentNode);
            std::cout << "Does " << node << " have neighbor " << adjacentNode << "? " << (hasNeighbor ? "Yes" : "No") << std::endl;
        }
    }

    return 0;
}
