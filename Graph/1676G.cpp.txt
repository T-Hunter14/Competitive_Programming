#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(int node, vector<int> adj[], vector<bool>& visited, string& s, vector<pair<int, int>>& ans) {
    visited[node] = true;
    int b = (s[node - 1] == 'B') ? 1 : 0;
    int w = (s[node - 1] == 'W') ? 1 : 0;
    for (int child : adj[node]) {
        if (!visited[child]) {
            pair<int, int> child_result = dfs(child, adj, visited, s, ans);
            b += child_result.first;
            w += child_result.second;
        }
    }
    ans[node] = {b, w};
    return ans[node];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> adj[n + 1];
        vector<bool> visited(n + 1, false);
        vector<pair<int, int>> ans(n + 1, {0, 0});
        for (int i = 2; i <= n; i++) {
            int x;cin >> x;
            adj[x].push_back(i);
        }
        string s;cin >> s;
        dfs(1, adj, visited, s, ans);
        int balanced_nodes = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i].first == ans[i].second) {
                balanced_nodes++;
            }
        }

        cout << balanced_nodes << endl;
    }

    return 0;
}