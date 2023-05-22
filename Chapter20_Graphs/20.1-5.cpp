// The square of a directed graph G = (V, E) is the graph G2 = (V, E2) such that
// (u, v) ∈ E2 if and only if G contains a path with at most two edges between u
// and v. Describe efficient algorithms for computing G2 from G for both the
// adjacency-list and adjacency-matrix representations of G. Analyze the running
// times of your algorithms.

#include <iostream>
#include <random>
#include <vector>

class Graph {
private:
  int numVertices;
  std::vector<std::vector<int>> adjacencyList;

public:
  Graph(int n) : numVertices(n), adjacencyList(n) {}

  void addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    // adjacencyList[v].push_back(u);
  }

  void printGraph() {
    for (int i = 0; i < numVertices; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (const auto &neighbor : adjacencyList[i]) {
        std::cout << neighbor << " ";
      }
      std::cout << std::endl;
    }
  }

  //     void makeSquareOfGraph()
  //     {
  //         for (int i = 0; i < numVertices; ++i) {
  //             std::cout << "Vertex " << i << ": ";
  //             for (const auto& neighbor : adjacencyList[i]) {
  //                 //std::cout << neighbor << " ";
  //                 auto neighbors_of_this_neighbor = adjacencyList[neighbor];

  //                 for ( auto e : neighbors_of_this_neighbor )
  //                 {
  //                     addEdge(i, e);
  //                 }
  //             }

  //             std::cout << std::endl;
  //         }
  //     }
  // };
  // void makeSquareOfGraph() {
  //   std::vector<std::pair<int, int>> newEdges; // Store new edges

  //   for (int i = 0; i < numVertices; ++i) {
  //     for (const auto &neighbor : adjacencyList[i]) {
  //       auto neighbors_of_this_neighbor = adjacencyList[neighbor];

  //       for (auto e : neighbors_of_this_neighbor) {
  //         newEdges.emplace_back(i, e); // Add new edges to the vector
  //       }
  //     }
  //   }

  //   // Add the new edges to the graph
  //   for (const auto &edge : newEdges) {
  //     addEdge(edge.first, edge.second);
  //   }
  // }

  void makeSquareOfGraph()
{
    std::vector<std::pair<int, int>> newEdges; // Store the new edges

    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (const auto& neighbor : adjacencyList[i]) {
            auto neighbors_of_this_neighbor = adjacencyList[neighbor];

            for (auto e : neighbors_of_this_neighbor) {
                newEdges.push_back(std::make_pair(i, e)); // Store the new edge
            }
        }

        std::cout << std::endl;
    }

    // Add the new edges to the graph
    for (const auto& edge : newEdges) {
        addEdge(edge.first, edge.second);
    }
}



};

int main() {
  // Create a graph with 5 vertices
  Graph graph(5);

  // Add edges to the graph
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(0, 4);

  for (int i = 0; i < 5; ++i) {
    int u = dis(gen);
    int v = dis(gen);
    graph.addEdge(u, v);
  }

  // Print the graph
  graph.printGraph();

  std::cout << "..\n";

  graph.makeSquareOfGraph();

  graph.printGraph();

  return 0;
}
