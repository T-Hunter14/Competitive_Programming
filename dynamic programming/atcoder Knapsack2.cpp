#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, W;
int dp[100001];
int w[101], v[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;
    int MAXV = 0;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        MAXV += v[i];
    }
    fill(dp, dp + MAXV + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = MAXV; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for (int i = MAXV; i >= 0; i--) {
        if (dp[i] <= W) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
