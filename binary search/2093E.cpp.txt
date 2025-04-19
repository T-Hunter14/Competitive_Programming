    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    using namespace std;
    
    //T-Hunter always should be safe :)
    
    using ull = unsigned long long;
    ull mul(ull a, ull b, ull mod) {
        return (ull)((__uint128_t)a * b % mod);
    }
    ull power(ull a, ull b, ull mod) {
        ull res = 1;
        a %= mod;
        while (b) {
            if (b & 1) res = mul(res, a, mod);
            a = mul(a, a, mod);
            b >>= 1;
        }
        return res;
    }
    bool miller(ull n, ull a) {
        if (n % a == 0) return false;
        ull d = n - 1;
        while (d % 2 == 0) d /= 2;
        ull x = power(a, d, n);
        if (x == 1 || x == n - 1) return true;
        while (d != n - 1) {
            x = mul(x, x, n);
            d *= 2;
            if (x == 1) return false;
            if (x == n - 1) return true;
        }
        return false;
    }
    bool isPrime(ull n) {
        if (n < 2) return false;
        if (n < 4) return true;
        if ((n & 1) == 0) return false;

        for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (a >= n) break;
            if (!miller(n, a)) return false;
        }
        return true;
    }
bool can(int mid, int k, const vector<int> &nums) {
        if (mid == 0) return true;
        int cnt = 0;
        vector<int> freq(mid);
        int distinct = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mid) {
                if (freq[nums[i]] == 0) distinct++;
                freq[nums[i]]++;
            }
            if (distinct == mid) {
                cnt++;
                fill(freq.begin(), freq.end(), 0);
                distinct = 0;
            }
        }
        return cnt >= k;
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t = 1;
        cin >> t;
        while (t--) {
           int n , k ;
            cin >> n >> k;
            int least  = n / k ;
            vector<int> v(n);
            map<int, int> mp;
            for (int i = 0; i < n; i++) cin >> v[i] , mp[v[i]] ++ ;
            int lo = 0 , hi = least;
            int ans = 0  ;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (can(mid, k, v)) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }