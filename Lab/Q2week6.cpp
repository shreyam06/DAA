#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
bool color(int u, int curr, vector<int> adj[], vector<bool> &visited, vector<int> &col)
{
    if (col[u] != -1 && col[u] != curr)
        return false;

    col[u] = curr;

    if (visited[u])
        return true;

    visited[u] = true;

    for (auto i : adj[u])
    {
        if (!color(i, curr xor 1, adj, visited, col))
            return false;
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;

    vector<bool> visited(N, false);
    vector<int> col(N, -1);
    vector<int> adj[N];

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && !color(i, 0, adj, visited, col))
        {
            cout << "not biparted";
            return 0;
        }
    }
    cout << "biparted";
    return 0;
}
