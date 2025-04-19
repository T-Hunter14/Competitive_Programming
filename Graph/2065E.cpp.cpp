#include <bits/stdc++.h>
using namespace std;
typedef long long  ll ;
void dfs(int node, vector<bool> &vis, vector<int> &path, vector<vector<int>> &paths, vector<set<int>> &adj) {
    vis[node] = true;
    path.push_back(node);

    bool isLeaf = true;
    for (int child : adj[node]) {
        if (!vis[child]) {
            isLeaf = false;
            dfs(child, vis, path, paths, adj);
        }
    }

    if (isLeaf) {
        paths.push_back(path);
    }
    path.pop_back();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
      int x , y , z ;
      cin >> x >> y >> z  ;
      ll mn = max(x , y ) - min (x , y ) ;
      ll mx = max(x , y ) ;
      bool check = false ;
      if(x >= y ) check = true;
      else check = false ;
      if(z >= mn && z <= mx  ){
          for(int i = 0 ; i < z  ; i++){
              if(check){
                  cout << '0' ;
                  x-- ;
              }else{
                  cout << '1';
                  y-- ;
              }
          }
          ll num = x + y ;
          for(int i = 0 ; i<num * 2 ; i++){
              if(check && y ){
                  y-- ;
                  cout <<'1' ;
                  check = !check ;
              }else if(!check && x ){
                  x-- ;
                  cout << '0' ;
                  check = !check ;
              }else {
                  check = !check ;
              }
          }
      }else{
          cout <<"-1";
      }
      cout <<endl;
    }
    return 0;
}