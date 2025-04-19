#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

bool can(ll mid , ll s)
{
    ll sum = 0 ;
    ll mid2= mid;
    while(mid)
    {
        sum+=mid%10;
        mid/=10;
    }
    return mid2 - sum >= s;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t =1;
//    cin >> t;
    while (t--) {
        ll n , s;
        cin >> n >> s;
        ll l = 10 , r = n , ans = 0 ;
        while (l<=r)
        {
            ll mid = (r + l ) / 2 ;
                    if(can(mid , s))
                    {
                        r = mid - 1;
                        ans =  mid ;
                    }else{
                        l = mid +1;
                    }
        }
        if(n - ans + 1 > n )cout<<0<<endl;
        else cout<< n - ans + 1<<endl;
    }
    return 0;
}