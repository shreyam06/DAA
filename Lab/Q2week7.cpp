#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord(vector<Edge>& edges, int numNodes, int source) {
    vector<int> distances(numNodes, INT_MAX);
    vector<int> parent(numNodes, -1);

    distances[source] = 0;
    for (int i = 1; i < numNodes; i++) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    for (int i = 0; i < numNodes; i++) {
        if (i == source) {
            continue;
        }

        vector<int> path;
        int currNode = i;

        while (currNode != -1) {
            path.push_back(currNode);
            currNode = parent[currNode];
        }

        cout << "Path from node " << i << " to node " << source << ": ";
        for (int j = path.size() - 1; j >= 0; j--) {
            cout << path[j];
            if (j != 0) {
                cout << " -> ";
            }
        }

        cout << " (Weight: " << distances[i] << ")\n";
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].source = u;
        edges[i].destination = v;
        edges[i].weight = w;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, numNodes, source);

    return 0;
}
