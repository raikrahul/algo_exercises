// Give an adjacency-list representation for a complete binary tree on 7 vertices.
// Give an equivalent adjacency-matrix representation.
// Assume that the edges are undirected and
// that the vertices are numbered from 1 to 7 as in a binary heap.

#include <iostream>
#include <vector>
using namespace std;

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



class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *createCompleteBinaryTree(int arr[], int index, int size, Graph& graph)
{
    if (index >= size)
        return nullptr;

    Node *root = new Node(arr[index]);
    root->left = createCompleteBinaryTree(arr, 2 * index + 1, size, graph);
    root->right = createCompleteBinaryTree(arr, 2 * index + 2, size, graph);
    // graph.addEdge(root->data, root->left->data);
    if (root->right)
        graph.addEdge(root->data, root->right->data);
    if (root->left)
        graph.addEdge(root->data, root->left->data);

    return root;
}

void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int numVertices = 7;
    Graph graph(numVertices);
    Node *root = createCompleteBinaryTree(arr, 0, size, graph);

    cout << "Inorder Traversal of the Complete Binary Tree: ";
    inorderTraversal(root);

    cout << "Adjancency List  of the Complete Binary Tree: ";
    graph.printGraph();

    return 0;
}
