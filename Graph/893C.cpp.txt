#include <bits/stdc++.h>
using namespace std;
int dfs (int node , vector<bool>&vis , vector<int > adj[] ,vector<int>&money ,  int &mn ){
    vis[node ] = true ;
    mn = min(mn , money[node]) ;
    for(auto it : adj[node]){
        if(!vis[it ]){
             dfs(it , vis , adj, money , mn ) ;
        }
    }
    return mn ;
}

typedef long long  ll ;
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int > adj[n + 1 ] , money(n + 1) ;
        vector<bool>visited (n + 1  , 0 );
        set <int >st ;
        for (int i = 1 ; i <= n  ; ++i) {
            cin >> money[i] ;
        }
        for (int i = 1  ; i <=  e ; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        ll  total = 0 ; int  mn = INT_MAX;
        for (int i = 1 ; i <= n  ; ++i) {
           if(!visited[i]) total+= dfs(i , visited , adj , money, mn ) ;
           mn=INT_MAX ;
        }
        cout << total <<endl;
    }
    return 0;
}