
// Given an adjacency-list representation of a directed graph,
// how long does it take to compute the out-degree of every vertex?
// How long does it take to compute the in-degrees?

#include <iostream>
#include <vector>

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
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int j : adjacencyList[i])
            {
                cout << j << " ";
            }
            cout << endl;
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

    int vertex = 3;
    int indegree = graph.indegree(vertex);
    std::cout << "Indegree of vertex " << vertex << ": " << indegree << std::endl;
    vertex = 1;
    int outdegree = graph.outdegree(vertex);
    std::cout << "Outdegree of vertex " << vertex << ": " << outdegree << std::endl;

    return 0;
}
