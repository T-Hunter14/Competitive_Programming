#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool all_possible_expressions(const vector<ll>& v, ll power, ll value) {
    if (power == (1 << v.size() + 1)) return false;
    ll comp = 0;
    ll comp2 = 0 ;
    for (int j = 0; j < (int)v.size(); ++j) {
        if (power & (1 << j))
            comp += v[j];
        else
            comp -= v[j];
    }
    if (comp == value) return true;
    return all_possible_expressions(v, power + 1, value);
}
ll max_matching (string s , string ss)
{
    ll cnt = 0 ;
    for(int i = 0 ;i  < s.size() ; i++) {
        if (s[i] != ss[i]) cnt++;
        else break;
    }
    return cnt;
}
int main() {
    int t = 1;
     cin >> t;
    while (t--) {
//        vector<ll> v(n);
//        for (auto &it : v) cin >> it;
        string s ;
        cin >> s;
        bool  startofzeros = false ;
        ll len = 0 ;
        ll cnt = 0 ;
        ll st = 0  ;
        string temp = "" ;
        for(auto it : s )
        {

            if(it == '0' && startofzeros == false) startofzeros = true , st = cnt ;
            cnt ++ ;
        }
        ll r = cnt - st ;
        ll mx = 0 ;
        ll l = 0 ;
        ll idx = 0 ;
        while (l + r < s.size()){
            if(max_matching(s.substr(l , r ) , s.substr(st , r )) > mx)
               mx = max_matching(s.substr(l , r ) , s.substr(st , r )) ,
               idx = l ;
            l ++ ;
        }
        if(mx == 0 )r = 1;
        cout <<"1 " <<s.size() <<" " ;
        cout << idx + 1   <<" " << idx + r <<endl;
    }
    return 0;
}