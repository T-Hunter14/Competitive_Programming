#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct value {
    ll count;
    char dir;
    ll idx;
};

bool compare(const value &a, const value &b) {
    if (a.count == b.count)
        return a.dir < b.dir;
    return a.count < b.count;
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
   ll n ; cin >> n ;
   ll s1 =0 , s2 =0 ;
   vector<ll>nega , pos ;
   ll last = -1 ;
        for (int i = 0; i < n ; ++i) {
            ll x ; cin >> x ;
            if(x > 0 )pos.push_back(x) , s1+=x ;
            else nega.push_back(x) , s2 += x ;
                if(x > 0 ) last = 1 ;
                else last  = 2 ;
        }
        if(s1 + s2 > 0 ) cout <<"first\n" ;
        else if(s2  + s1 < 0  ) cout <<"second\n" ;
        else {
            bool bb = false ;
                vector<ll> seq;
                for (int i = 0; i < min(nega.size(), pos.size()); i++) {
                    if (abs(nega[i]) > pos[i]){cout <<"second\n" ; bb= true ;
                        break;}
                    else if (abs(nega[i]) < pos[i]) { cout << "first\n"; bb = true ;
                        break; }
                    else continue;
                }
                if(bb)continue;
                else {
                    if(nega.size() - pos.size() != 0 ){
                        if(nega.size() > pos.size()) cout <<"second\n" ;
                        else cout <<"first\n" ;
                    }else {
                    if (last == 1) cout << "first\n";
                    else cout << "second\n";
                }
            }
        }
    }
    return 0;
}