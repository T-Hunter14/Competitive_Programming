#include <bits/stdc++.h > ;
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n ; cin >> n ;
        ll first = 0  , sec = 0 ;
        bool turn = true ;
        while (n) {
            if (n <= 10) {
                if ((n & 1) == 0) {
                    if (turn) {
                        first += n / 2;
                        n /= 2;
                        turn = !turn;
                    }
                    else {
                        sec == n / 2;
                        n /= 2;
                        turn = !turn;
                    }
                } else {
                    if (turn) {
                        first++;
                        n--;
                        turn = !turn;
                    }
                    else {
                        sec++;
                        n--;
                        turn = !turn;
                    }
                }
            } else {
                if ((n & 1) == 0 && ((n / 2) % 2 != 0)) {
                    if (turn) {
                        first += n / 2;
                        n /= 2;
                        turn = !turn;
                    }
                    else {
                        sec == n / 2;
                        n /= 2;
                        turn = !turn;
                    }
                } else {
                    if (turn) {
                        first++;
                        n--;
                        turn = !turn;
                    }
                    else {
                        sec++;
                        n--;
                        turn = !turn;
                    }
                }
            }
        }
        cout << first << endl;
    }
    return 0;
}