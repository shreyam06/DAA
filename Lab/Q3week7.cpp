#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Infinite distance

int shortestPathWithKEdges(vector<vector<int>>& graph, int source, int destination, int k) {
    int numVertices = graph.size();

    vector<vector<vector<int>>> dp(numVertices, vector<vector<int>>(numVertices, vector<int>(k + 1, INF)));

    if (k == 0 && source == destination) {
        return 0;
    }

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            dp[i][j][0] = graph[i][j];
        }
    }

    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                dp[u][v][e] = dp[u][v][e - 1]; // The shortest path with e edges is the same as the shortest path with e-1 edges

                for (int w = 0; w < numVertices; w++) {
                    if (dp[u][w][e - 1] != INF && graph[w][v] != INF) {
                        dp[u][v][e] = min(dp[u][v][e], dp[u][w][e - 1] + graph[w][v]);
                    }
                }
            }
        }
    }

    return dp[source][destination][k];
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                graph[i][j] = INF; // Convert -1 to infinite distance
            }
        }
    }

    int source, destination, k;

    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;
    cout << "Enter the number of edges (k): ";
    cin >> k;

    int shortestPathWeight = shortestPathWithKEdges(graph, source, destination, k);

    if (shortestPathWeight == INF) {
        cout << "There is no path from source to destination with exactly " << k << " edges.\n";
    } else {
        cout << "The weight of the shortest path from source to destination with exactly " << k
             << " edges is: " << shortestPathWeight << endl;
    }

    return 0;
}
