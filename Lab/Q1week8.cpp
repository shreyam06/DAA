#include <iostream> 
#include <vector> 
#include <queue> 
#include <climits>

using namespace std;

struct Edge
{
    int destination;
    int weight;
};

class Graph
{
    int numVertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int numVertices) : numVertices(numVertices), adjacencyList(numVertices) {}

    void addEdge(int source, int destination, int weight)
    {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight});
    }

    int minimumCost()
    {
        vector<bool> visited(numVertices, false);
        vector<int> key(numVertices, INT_MAX);
        vector<int> parent(numVertices, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int source = 0;
        pq.push(make_pair(0, source));
        key[source] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;

            for (const auto &edge : adjacencyList[u])
            {
                int v = edge.destination;
                int weight = edge.weight;

                if (!visited[v] && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                }
            }
        }

        int minimumCost = 0;
        for (int i = 1; i < numVertices; i++)
        {

            minimumCost += key[i];
        }

        return minimumCost;
    }
};

int main()
{
    int numVertices;
    cout << "Enter the number of cities: ";
    cin >> numVertices;

    Graph graph(numVertices);

    int numRoads = numVertices - 1;
    cout << "Enter the details of " << numRoads << " roads:\n";
    for (int i = 0; i < numRoads; i++)
    {
        int source, destination, cost;
        cout << "Enter the source, destination, and cost of road " << i + 1 << ": ";
        cin >> source >> destination >> cost;
        graph.addEdge(source, destination, cost);
    }

    int minimumCost = graph.minimumCost();
    cout << "Minimum cost required to connect the cities: " << minimumCost << endl;

    return 0;
}
