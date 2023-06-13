#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class
class Graph
{
    int V;                   // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void BFS(int startVertex, vector<int> &d, vector<int> &pi)
    {
        vector<bool> visited(V, false); // track visited vertices
        queue<int> q;                   // queue for BFS traversal

        visited[startVertex] = true; // mark start vertex as visited
        q.push(startVertex);         // enqueue start vertex

        while (!q.empty())
        {
            int currVertex = q.front();
            cout << currVertex << " "; // process current vertex
            q.pop();

            // visit all adjacent vertices of current vertex
            for (int adjVertex : adj[currVertex])
            {
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    d[adjVertex] = d[currVertex] + 1;
                    pi[adjVertex] = currVertex;

                    q.push(adjVertex);
                }
            }
        }
    }
};

int main()
{
    int numVertices = 6;
    Graph graph(numVertices);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    int startVertex = 0; // choose a start vertex

    cout << "BFS traversal starting from vertex " << startVertex << ": ";

    vector<int> d(numVertices, 0);   // distance from startVertex
    vector<int> pi(numVertices, -1); // predecessor vertex

    graph.BFS(startVertex, d, pi);

    cout << "d values:\n";
    for (int i = 0; i < numVertices; i++)
    {
        cout << "d[" << i << "] = " << d[i] << endl;
    }

    cout << "\nπ values:\n";
    for (int i = 0; i < numVertices; i++)
    {
        cout << "π[" << i << "] = " << pi[i] << endl;
    }

    return 0;
}
