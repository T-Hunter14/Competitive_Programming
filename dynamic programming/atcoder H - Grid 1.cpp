#include <bits/stdc++.h>
using namespace std;
typedef long long  ll ;
const int N = 1005 ;
char arr[N][N] ;
int n , m ;
int ans = 0  ;
int dp[N][N] ;
int  solve(int i, int j) {
    if(i >= n || j >= m || arr[i][j] == '#' )return 0  ;
    if(i == n - 1 && j == m - 1 ) return 1 ;
    if(~dp[i][j])return dp[i][j] ;
    int ch1 = 0 , ch2 = 0 ;
        ch1 = solve(i , j + 1 ) ;
        ch2 = solve(i + 1 , j);
    return  dp[i][j]  = (ch1 % 1000000007  + ch2  %1000000007 ) % 1000000007 ;
}

int main() {
    cin >> n  >> m ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> arr[i][j] ;
        }
    }

    memset(dp , -1 , sizeof dp) ;
    cout << solve(0 , 0) ;
    return 0;
}
