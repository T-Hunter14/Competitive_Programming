#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 5, mod = 1e9 + 7; // تقليل قيمة N لتكون مناسبة

// دالة تتحقق من أولية العدد
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// دالة لحساب القاسم الأكبر المشترك
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// دالة لحساب المضاعف الأصغر المشترك
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// دالة لحساب الأس
ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll x = power(a, b / 2);
    x *= x;
    if (b % 2 != 0) x *= a;
    return x;
}

// دالة للتشفير بتقنية إيراتوستينس
vector<bool> isPrime(N, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// دالة للتشفير الخطى
vector<bool> ISPrime(N, true);
set<ll> primes;
void linearSieve() {
    ISPrime[0] = ISPrime[1] = false;
    for (ll i = 2; i < N; i++) {
        if (ISPrime[i]) primes.insert(i);
        for (auto it : primes) {
            if (i * it >= N) break;
            ISPrime[i * it] = false;
            if (i % it == 0) break;
        }
    }
}

// دالة لتجزئة العدد إلى عوامل أولية
vector<pair<ll, ll>> primeFactorize(ll n) {
    vector<pair<ll, ll>> arr;
    for (ll i = 2; i * i <= n; i++) {
        int w = 0;
        while (n % i == 0) {
            w++;
            n /= i;
        }
        if (w) arr.push_back({i, w});
    }
    if (n > 1) arr.push_back({n, 1});
    return arr;
}

// دالة لإيجاد جميع القواسم لعدد معين
vector<ll> divisors(ll n) {
    vector<ll> arr;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            arr.push_back(i);
            if (i != n / i) arr.push_back(n / i);
        }
    }
    sort(arr.begin(), arr.end());
    return arr;
}

// دالة لحساب الأس بطريقة التشفير المعياري
ll powmod(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

// دوال العمليات الحسابية بتقنية التشفير المعياري
ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}
ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
ll sub(ll a, ll b) {
    return ((((a % mod) - (b % mod)) % mod) + mod) % mod;
}
ll divide(ll a, ll b) {
    return mul(a, powmod(b, mod - 2));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
        if (is_prime(n)) {
            cout << 1 << endl << n;
        } else if (is_prime(n)) {
            cout << 3 << endl << n - 4 << " " << 2 << " " << 2;
        } else if (is_prime(n - 6)) {
            cout << 3 << endl << n - 6 << " " << 3 << " " << 3;
        } else if (is_prime(n - 2)){
            cout << 2 << endl << n - 2 << " " << 2;
        } else if (is_prime(n - 8 )) {
            cout << 3 << endl << n - 8 << " " << 3 << " " << 5;
        }
        else if (is_prime(n - 10 )) {
            cout << 3 << endl << n - 10 << " " << 5 << " " << 5;
        }else{
            ll copy = n ;
            copy-=2;
              while(!is_prime(copy))
              {
                  copy-=2;
              }
              n -=copy;
              linearSieve();
              auto it = primes.begin();
              while(true)
              {
                  if(primes.count(n - *it)==1)
                  {
                      cout<< 3<<endl<<copy<<" "<< *it<<" "<<n - *it;
                      return  0 ;
                  }
                  it++;
              }
    }
    return 0;
}