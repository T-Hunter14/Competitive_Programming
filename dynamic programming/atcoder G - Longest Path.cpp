#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , e ;
int dp[100004] ;
vector<int> v [100004] ;
int  dfs (int node  ) {
    if (dp[node] != -1) {
        return dp [ node ];
    }
    int best = 0 ;
    for (auto it : v[node ]) {
        int op = 1 + dfs(it ) ;
        best = max(best , op) ;
    }
    return dp[node] = best ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ;
    // cin >> t ;
    while (t--) {
        cin >> n >> e ;
        // vector<int> v[n + 1];
        for (int i = 0; i < e; i++) {
            int x , y ;
            cin >> x >> y ;
            v[x].push_back(y);
            int want = x ;
        }
        fill(dp , dp + n + 1 , -1) ;
        int ans = 0 ;
        for (int i = 1; i <= n; i++) {
            ans = max(ans , dfs(i)) ;
        }
        cout << ans << endl ;
    }
    return 0;
}
