    #include <bits/stdc++.h>
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
            ll n  ;
            cin >> n  ;
            vector<ll>v1(n) , v2(n) ;
            map <ll , ll >mp ;
            ll cnt =0 ;
            for(auto &it : v1 ) cin >> it , mp[it] =cnt++  ;
            cnt = 0 ;
            for(auto &it : v2 ) cin >> it , mp[it] = cnt++;
            ll ans = n ;
            ll first = n ;
            for(int i =n * 2 ; i >=2; i -=2)
            {
                // انا الاول بجرب الرقم الزوجي مع اول رقم فردي ينفع معاه و لو لقيت ان الزوجي دا ف مكان مناسب اسيبه لانه هيبقا متاح لكل اللي بعده
                first = min(first , mp[i]) ;//افضل مكان لعنصر كبير
                ans = min (ans , first+mp[i - 1]) ;  // انا ضامن ان الفيرست اكبر ف باخد البيست مع  i - 1
            }
            cout << ans <<'\n';
        }
        return 0;
    }