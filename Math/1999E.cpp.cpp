#include <bits/stdc++.h>
using namespace std;
typedef long long ll  ;
int main() {
    int t  ;
    cin >> t ;
    while (t--) {
        ll n , m ; cin >> n >> m ;
        ll cnt = 0  ;
        ll prev = n ;
        while (n) {
            n/=3;
            cnt++ ;
        }
        ll cnt2 = cnt ;
        ll ans = 0 ;
        while (true) {
            ll st = min (m  , (ll)pow(3 , cnt)) ;
            ll mn = max (prev  ,(ll) pow(3 , cnt  - 1)) ;
            ans+= ( st - mn  ) * cnt ;
            cnt++;
            if(pow(3 , cnt -1 ) > m )break;
        }
        if(pow(3 , cnt -2 ) <= m )
            ans+=cnt - 1  ;
        cout << cnt2 +ans <<endl;
    }
    return 0;
}