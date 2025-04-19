#include <bits/stdc++.h>
using namespace std;
void dfs (int node , vector<bool>&vis , vector<int > adj[]){
    vis[node ] = true ;
    for(auto it : adj[node]){
        if(!vis[it ])dfs(it , vis , adj) ;
    }
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int > adj[n + 1 ];
        vector<bool>visited (n + 1  , 0 );
        set <int >st ;
        for (int i = 1  ; i <=  e ; ++i) {
            int u , v; cin >> u >> v ;
            st.insert(u) ; st.insert(v) ;
        }
        for(int i = 1 ; i<= n ; i ++)
        {
            if(st.count(i) == 0 ){
                cout << n - 1 <<'\n' ; 
                for (int j = 1 ; j <= n ; ++j) {
                    if(j != i ) cout << i <<" " << j << '\n' ;
                }
                return 0 ;
            }
        }
    }
    return 0;
}