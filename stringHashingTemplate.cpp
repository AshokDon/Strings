#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_add(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a + b) % m;
}

ll mod_sub(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a - b + m) % m;
}

ll mod_mul(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (a * b) % m;
}

ll binpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1;
    }
    return res;
}

// Modular inverse for prime modulus using Fermat's Little Theorem
ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}

struct Hashing {
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 1000000007};  // 2 large primes
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;

    Hashing(string a) {
        s = a;
        n = s.length();
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);

        for (int i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                powersOfBase[i][j] = mod_mul(base, powersOfBase[i][j - 1], hashPrimes[i]);
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--) {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }

        for (int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++) {
                hashValues[i][j] = mod_mul(s[j] - 'a' + 1, powersOfBase[i][j], hashPrimes[i]);
                if (j > 0)
                    hashValues[i][j] = mod_add(hashValues[i][j], hashValues[i][j - 1], hashPrimes[i]);
            }
        }
    }

    // Get hash of substring s[l...r]
    vector<ll> substringHash(int l, int r) {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++) {
            ll val = hashValues[i][r];
            if (l > 0)
                val = mod_sub(val, hashValues[i][l - 1], hashPrimes[i]);
            hash[i] = mod_mul(val, inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
int main() {
    string str = "abcabc";
    Hashing H(str);
    auto h1 = H.substringHash(0, 2);  // hash of "abc"
    auto h2 = H.substringHash(3, 5);  // hash of second "abc"
    if (h1 == h2) cout << "Equal\n";  // should print "Equal"
    else cout << "Not Equal\n";
}
