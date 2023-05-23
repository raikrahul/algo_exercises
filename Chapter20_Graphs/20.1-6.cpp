// Most graph algorithms that take an adjacency-matrix representation as input require Ω(V2) time, 
// but there are some exceptions. 
// Show how to determine whether a directed graph G 
// contains a universal sink—a vertex with in-degree |V| – 1 
// and out-degree 0—in O(V) time, given an adjacency matrix for G.

#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>

class Graph {
private:
    int numVertices;
    std::vector<std::unordered_set<int>> adjacencyList;
    std::vector<int> indegree;
    std::vector<int> outdegree;

public:
    Graph(int n) : numVertices(n), adjacencyList(n) {

        indegree.assign(numVertices, 0);
        outdegree.assign(numVertices, 0);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].insert(v);
        // Uncomment the following line if the graph is undirected
        // adjacencyList[v].insert(u);
        outdegree[u]++;
        indegree[v]++;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (auto v : adjacencyList[i])
                std::cout << v << " ";
            std::cout << std::endl;
        }
    }

    bool contains_sink()
    {
        for (int i = 0; i < numVertices; ++i) {
            //std::cout << "Vertex " << i << ": ";
            // for (auto v : adjacencyList[i])
            if ( indegree[i] == numVertices -1 and outdegree[i] == 0)
            {
                std::cout << "\ngraph contains sink at vertex " << i << R"(
)";
                return true;
            }
            std::cout << std::endl;
        }
        return false;
    }
    // Run in O(V)
};

int main() {
    int numVertices = 5;
    int numEdges = 8;

    // Create a graph with 5 vertices
    Graph graph(numVertices);

    // Generate random edges
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, numVertices - 1);

    // for (int i = 0; i < numEdges; ++i) {
    //     int u = dis(gen);
    //     int v = dis(gen);
    //     graph.addEdge(u, v);
    // }

    for (int i = 0; i < numVertices; ++i) {
        if (i != numVertices - 1) {
            graph.addEdge(i, numVertices - 1);
        }
    }
    // Print the graph
    bool res = graph.contains_sink();
    graph.printGraph();

    return 0;
}
