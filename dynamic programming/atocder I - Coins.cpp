#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
long double arr[3000];
long double dp[3000][3000];
bool vis[3000][3000];

long double solve(int i, int h) {
    if (i == n) return (h > n / 2 ? 1.0 : 0.0);
    if (vis[i][h]) return dp[i][h];

    vis[i][h] = true;

    // الاحتمال إن العملة تطلع صورة
    long double op1 = arr[i] * solve(i + 1, h + 1);
    // الاحتمال إنها تطلع كتابة
    long double op2 = (1 - arr[i]) * solve(i + 1, h);
    return dp[i][h] = op1 + op2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << fixed << setprecision(10) << solve(0, 0) << endl;
    return 0;
}
