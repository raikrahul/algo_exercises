

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

const int MAX_NODES = 100; // Maximum number of nodes in the graph

void addEdge(std::vector<std::vector<int>> &graph, int u, int v) {
  graph[u][v] = 1; // Set edge from u to v
                   // Uncomment the line below if the graph is undirected
                   // graph[v][u] = 1;  // Set edge from v to u
}

void transpose(std::vector<std::vector<int>> &graph, int numNodes) {

  for (int i = 0; i < numNodes; ++i) {
    for (int j = 0; j < numNodes; ++j) {
      // std::cout << graph[i][j] << " ";
      graph[i][j] = !graph[i][j];
    }
    std::cout << std::endl;
  }
}
// O(n*m)

void transpose(vector<bool> &matrix, int numNodes) {
  for (int i = 0; i < numNodes; ++i) {
    for (int j = i + 1; j < numNodes; ++j) {
      std::swap_ranges(matrix.begin() + (i * numNodes + j),
                       matrix.begin() + (i * numNodes + j) + 1,
                       matrix.begin() + (j * numNodes + i));
    }
  }
}
// O(0.5 * n *m )
// this matrix is symmetric for directed graphs
// in one iteration one can swap the elemtns // on the upper left diagnal
//

void transposeFlatDirected(std::vector<std::vector<int>> graph, int numNodes) {
  std::vector<int> flattenedVector;

  // Iterate over the lower triangular part (including the main diagonal)
  for (int i = 0; i < graph.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      flattenedVector.push_back(graph[i][j]);
    }

    std::reverse(flattenedVector.begin(), flattenedVector.end());
    int index = 0;

    for (int i = 0; i < graph.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        graph[i][j] = flattenedVector[index];
        graph[j][i] = flattenedVector[index];
        ++index;
      }
    }

  } //

  void printGraph(const std::vector<std::vector<int>> &graph, int numNodes) {
    std::cout << "Graph representation (Adjacency Matrix):" << std::endl;
    for (int i = 0; i < numNodes; ++i) {
      for (int j = 0; j < numNodes; ++j) {
        std::cout << graph[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  int main() {
    int numNodes = 5; // Number of nodes in the graph
    std::vector<std::vector<int>> graph(numNodes,
                                        std::vector<int>(numNodes, 0));

    addEdge(graph, 0, 1); // Add edge from node 0 to node 1
    addEdge(graph, 0, 2); // Add edge from node 0 to node 2
    addEdge(graph, 1, 3); // Add edge from node 1 to node 3
    addEdge(graph, 2, 3); // Add edge from node 2 to node 3
    addEdge(graph, 3, 4); // Add edge from node 3 to node 4

    printGraph(graph, numNodes);

    transpose(graph, numNodes);

    printGraph(graph, numNodes);

    return 0;
  }
