

// Given an adjacency-list representation of a multigraph 
// G = (V, E), describe an O(V + E)-time algorithm to compute the 
// adjacency-list representation of the “equivalent” undirected graph G′ = (V, E′), 
// where E′ consists of the edges in E with all 
// multiple edges between two vertices replaced by a single edge and with all 
// self-loops removed.


#include <iostream>
#include <unordered_set>
#include <vector>
// #include <ranges>

using std::cout;

struct edge {
  int dest;
  int count;
};

bool operator==(const struct edge a, const struct edge b)
{
  return a.dest == b.dest; 
};

struct EdgeHash {
  std::size_t operator()(const edge& e) const {
    return std::hash<int>()(e.dest);
  }
};
class Graph {
private:
  int numVertices;
  std::vector<std::vector<struct edge>> adjacencyList;

public:
  Graph(int n) : numVertices(n), adjacencyList(n) {}

  void addEdge(int u, int v) {
    bool exists;
    for (auto &e : adjacencyList[u]) {
      if (e.dest == v) {
        e.count++;
        exists = true;
        break;
      }
    }
    // Uncomment the following line if the graph is undirected
    // adjacencyList[v].push_back(u);
    if (!exists) {
      adjacencyList[u].push_back({v, 1});
    }
  }

  void printGraph() {
    for (int i = 0; i < numVertices; ++i) {
      std::cout << "Vertex " << i << ": ";
      for (auto const e : adjacencyList[i])
        cout << e.dest << "  has " << e.count << " edges ";
      std::cout << std::endl;
    }
  }

  void printGraphEquivalent() {
    for (int i = 0; i < numVertices; ++i) {
      std::cout << "Vertex " << i << ": ";
      // for (auto const e : adjacencyList[i])
      //   cout << e.dest << "  has " << e.count << " edges ";
      auto eu = std::unordered_set<struct edge, EdgeHash>(adjacencyList[i].begin(), adjacencyList[i].end());
      // std::copy(eu.begin(), eu.end(), std::ostream_iterator<int>(std::cout, " "));
     //std::ranges::copy(eu, std::ostream_iterator<struct edge>(std::cout, " "));
      for ( const auto e : eu)
      {
        std::cout << e.dest << "  ";
      }
      std::cout << std::endl;
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
  graph.addEdge(0, 1);
  graph.addEdge(0, 4);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);

  // Print the graph
  graph.printGraph();

  std::cout << "           " << std::endl;
  graph.printGraphEquivalent();

  return 0;
}
