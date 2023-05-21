// The transpose of a directed graph G = (V, E) is the graph GT = (V, ET), 
// where ET = {(v, u) ∈ V × V : (u, v) ∈ E}. 
// That is, GT is G with all its edges reversed. 
// Describe efficient algorithms for computing GT from G, 
//for both the adjacency-list and 
// adjacency-matrix representations of G. 
// Analyze the running times of your algorithms
#include <vector>
#include <iostream>
#include <algorithm>

class Graph
{
private:
public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}

    void addEdge(int source, int destination)
    {
        adjacencyList.at(source).push_back(destination);
    }

    void printGraph()
    {
        std::cout << "\n";
        for (int i = 0; i < numVertices; i++)
        {
            std::cout << "Vertex " << i << " -> ";
            for (int j : adjacencyList[i])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
    int outdegree(int vertex)
    {
        return adjacencyList[vertex].size();
    } // constant time

    int indegree(int vertex)
    {
        int res = 0;

        for (auto const e : adjacencyList)
        {
            for (auto const ee : e)
            {
                if (vertex == ee)
                {
                    res++;
                }
            }
        }
        return res;
    } // O(n*m time = n^2 time)


    void transpose()
    {
        for ( auto& e:adjacencyList)
        {
            std::reverse(e.begin(), e.end());
        }
    }
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};

int main()
{
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    graph.transpose();

    graph.printGraph();

    return 0;

}
