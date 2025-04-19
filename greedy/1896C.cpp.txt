\    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll ;
    bool isPrime(int n) {
        if (n <= 1) return false; // Numbers <= 1 are not prime
        if (n <= 3) return true;  // 2 and 3 are prime
        if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

        // Check factors from 5 to √n
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    std::vector<std::pair<int, int>> primeFactorization(int n, const std::vector<int>& primes) {
        std::vector<std::pair<int, int>> factors;

        for (int prime : primes) {
            if (prime * prime > n) break; // No need to check beyond √n

            int count = 0;
            while (n % prime == 0) {
                n /= prime;
                ++count;
            }
            if (count > 0) {
                factors.emplace_back(prime, count);
            }
        }

        // If `n` is still greater than 1, it is a prime number
        if (n > 1) {
            factors.emplace_back(n, 1);
        }

        return factors;
    }

    int main() {
        int t = 1;
        cin >> t;
        while (t--) {
            ll n , k ;
            cin >> n >> k ;
            vector<pair<ll ,ll >>v1(n);
            vector<ll>v2(n);
            ll cnt =0 ;
            for(auto &it : v1 ) cin >> it.first , it.second = cnt , cnt ++ ;
            for(auto &it : v2 ) cin >> it ;
            vector<pair<ll , ll >>v3(v1.begin(), v1.end()) ;
            sort(v1.begin(), v1.end()) ;
            sort(v2.begin(), v2.end() , greater<>());
            sort(v2.begin()+(n - k) , v2.end()) ;
            sort(v2.begin() , v2.begin()+(n - k) ) ;
            ll ans = 0 ;
            map <pair<ll , ll > , ll > mp ;
            for(int i = 0; i< n ; i ++)
            {
                mp[{v1[i].first , v1[i].second}] = v2[i] ;
                if(v1[i].first > v2[i]){
                    ans ++ ;
                }
            }
            if(ans == k ) {
                cout << "YES\n";
                for(auto it : v3){
                    cout << mp[{it.first , it.second}]<<' ' ;
                }
                cout <<'\n';
            }
            else cout <<"NO\n";
        }
        return 0;
    }