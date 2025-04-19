#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n ;
int voc [100001][3] ;
// int dp[100001][3] ;
int dp[100001][4] ;

int solve(int i = 0, int j = 3) {
    if (i == n) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    int op1 = 0, op2 = 0, op3 = 0;
    if (j != 0) op1 = voc[i][0] + solve(i + 1, 0);
    if (j != 1) op2 = voc[i][1] + solve(i + 1, 1);
    if (j != 2) op3 = voc[i][2] + solve(i + 1, 2);
    return ret = max({op1, op2, op3});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t =1 ;
    // cin >> t;
    while (t--) {
        cin >> n ;
        memset(dp , -1 , sizeof(dp)) ;
        for (int i = 0 ; i < n ; i++) {
            cin >> voc[i][0] >> voc[i][1] >> voc[i][2];
        }
        cout << solve() << endl ;
    }
    return 0;
}
