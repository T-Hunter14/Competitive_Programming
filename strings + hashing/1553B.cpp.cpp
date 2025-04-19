#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE1 = 31;
const int BASE2 = 53;

inline int add(int a, int b, int mod) {
    a += b; if (a >= mod) a -= mod;
    return a;
}
inline int subm(int a, int b, int mod) {
    a -= b; if (a < 0) a += mod;
    return a;
}
inline int mul(int a, int b, int mod) {
    return (int)((ll)a * b % mod);
}
ll modexp(ll a, ll e, int mod) {
    ll res = 1; a %= mod;
    while (e) {
        if (e & 1) res = res * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return res;
}

vector<int> pw1, inv1, pw2, inv2;

void init_hash(int n) {
    pw1.assign(n+1,1);
    inv1.assign(n+1,1);
    pw2.assign(n+1,1);
    inv2.assign(n+1,1);
    int ib1 = (int)modexp(BASE1, MOD1-2, MOD1);
    int ib2 = (int)modexp(BASE2, MOD2-2, MOD2);
    for (int i = 1; i <= n; i++) {
        pw1[i]  = mul(pw1[i-1], BASE1, MOD1);
        inv1[i] = mul(inv1[i-1], ib1, MOD1);
        pw2[i]  = mul(pw2[i-1], BASE2, MOD2);
        inv2[i] = mul(inv2[i-1], ib2, MOD2);
    }
}

void build_hash(const string &s, vector<pair<int,int>>& H) {
    int n = s.size(); H.resize(n);
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; i++) {
        int v = s[i] - 'a' + 1;
        h1 = add(h1, mul(v, pw1[i], MOD1), MOD1);
        h2 = add(h2, mul(v, pw2[i], MOD2), MOD2);
        H[i] = {h1, h2};
    }
}

pair<int,int> get_hash(int l, int r, const vector<pair<int,int>>& H) {
    auto [a1,a2] = H[r];
    if (l > 0) {
        a1 = subm(a1, H[l-1].first, MOD1);
        a2 = subm(a2, H[l-1].second, MOD2);
    }
    a1 = mul(a1, inv1[l], MOD1);
    a2 = mul(a2, inv2[l], MOD2);
    return {a1, a2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    // ننشئ pw و inv بحيث يغطي أطوال السلاسل حتى 1000 (s2 قد يصل لطول ~2*s1-1)
    init_hash(1000);
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.size(), m = s2.size();

        vector<pair<int,int>> H1, H2, H3;
        build_hash(s1, H1);
        build_hash(s2, H2);
        string rs = s1; reverse(rs.begin(), rs.end());
        build_hash(rs, H3);

        bool ok = false;
        for (int i = 0; i < m && !ok; i++) {
            int len1 = i + 1;
            int len2 = m - len1;
            if (len1 > n1) break;
            if (len2 > n1) continue;

            auto hA = get_hash(0, i, H2);
            auto hB = len2 ? get_hash(i+1, m-1, H2) : make_pair(0,0);

            for (int j = 0; j + len1 - 1 < n1; j++) {
                auto h1_sub = get_hash(j, j + len1 - 1, H1);
                if (h1_sub != hA) continue;

                if (len2 == 0) {
                    ok = true;
                    break;
                }

                int endA = j + len1 - 1;
                if (len2 > endA) continue;

                int l2 = endA - len2;
                int r2 = endA - 1;
                int rev_l = n1 - 1 - r2;
                int rev_r = n1 - 1 - l2;
                auto h1_rev = get_hash(rev_l, rev_r, H3);
                if (h1_rev == hB) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}