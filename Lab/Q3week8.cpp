#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

struct Edge
{
    int source;
    int destination;
    int weight;
};

class Graph
{
    int numVertices;
    vector<Edge> edges;

public:
    Graph(int numVertices) : numVertices(numVertices) {}

    void addEdge(int source, int destination, int weight)
    {
        edges.push_back({source, destination, weight});
    }

    static bool compareEdges(const Edge &a, const Edge &b)
    {
        return a.weight > b.weight;
    }

    int maximumBudget()
    {
        sort(edges.begin(), edges.end(), compareEdges);

        vector<int> parent(numVertices, -1);
        vector<int> rank(numVertices, 0);

        int maximumWeight = 0;

        for (const auto &edge : edges)
        {
            int sourceRoot = findRoot(parent, edge.source);
            int destinationRoot = findRoot(parent, edge.destination);

            if (sourceRoot != destinationRoot)
            {
                maximumWeight += edge.weight;
                unionSets(parent, rank, sourceRoot, destinationRoot);
            }
        }

        return maximumWeight;
    }

private:
    int findRoot(vector<int> &parent, int vertex)
    {
        if (parent[vertex] == -1)
            return vertex;

        return findRoot(parent, parent[vertex]);
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int root1, int root2)
    {
        if (rank[root1] < rank[root2])
        {
            parent[root1] = root2;
        }
        else if (rank[root1] > rank[root2])
        {
            parent[root2] = root1;
        }
        else
        {
            parent[root1] = root2;
            rank[root2]++;
        }
    }
};

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            int weight;
            cin >> weight;
            if (weight != 0)
                graph.addEdge(i, j, weight);
        }
    }

    int maximumBudget = graph.maximumBudget();
    cout << "Maximum budget required for the project: " << maximumBudget << endl;

    return 0;
}
