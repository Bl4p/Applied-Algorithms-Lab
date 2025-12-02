#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    vector<int> earliest_finish(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            earliest_finish[i] = d[i];
        }
    }

    int project_completion_time = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        project_completion_time = max(project_completion_time, earliest_finish[u]);

        for (int v : adj[u]) {
            earliest_finish[v] = max(earliest_finish[v], earliest_finish[u] + d[v]);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << project_completion_time << endl;

    return 0;
}