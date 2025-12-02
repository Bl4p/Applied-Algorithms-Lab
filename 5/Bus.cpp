#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> C(n + 1);
    vector<int> D(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> C[i] >> D[i];
    }

    vector<vector<int>> adj_road(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_road[u].push_back(v);
        adj_road[v].push_back(u);
    }

    vector<vector<pair<int, int>>> adj_cost(n + 1);

    for (int i = 1; i <= n; ++i) {
        queue<pair<int, int>> q;
        q.push({i, 0});
        
        vector<bool> visited(n + 1, false);
        visited[i] = true;

        while (!q.empty()) {
            auto [u, dist] = q.front();
            q.pop();

            if (u != i) {
                adj_cost[i].push_back({u, C[i]});
            }

            if (dist < D[i]) {
                for (int v : adj_road[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push({v, dist + 1});
                    }
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> min_cost(n + 1, INF);

    min_cost[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > min_cost[u]) continue;

        for (auto [v, weight] : adj_cost[u]) {
            if (min_cost[u] + weight < min_cost[v]) {
                min_cost[v] = min_cost[u] + weight;
                pq.push({min_cost[v], v});
            }
        }
    }

    if (min_cost[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cost[n] << endl;
    }

    return 0;
}