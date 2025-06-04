#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll BASE = 31;

ll mod_add(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a + b) % MOD;
}

ll mod_sub(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a - b + MOD) % MOD;
}

ll mod_mul(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a * b) % MOD;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a) {
    return binpow(a, MOD - 2);
}

struct Hashing {
    string s;
    int n;
    vector<ll> hashValues;
    vector<ll> powers;
    vector<ll> invPowers;

    Hashing(string str) {
        s = str;
        n = s.length();
        hashValues.resize(n);
        powers.resize(n + 1);
        invPowers.resize(n + 1);

        powers[0] = 1;
        for (int i = 1; i <= n; i++)
            powers[i] = mod_mul(powers[i - 1], BASE);

        invPowers[n] = mod_inv(powers[n]);
        for (int i = n - 1; i >= 0; i--)
            invPowers[i] = mod_mul(invPowers[i + 1], BASE);

        for (int i = 0; i < n; i++) {
            hashValues[i] = mod_mul(s[i] - 'a' + 1, powers[i]);
            if (i > 0) hashValues[i] = mod_add(hashValues[i], hashValues[i - 1]);
        }
    }

    ll getHash(int l, int r) {
        ll hash = hashValues[r];
        if (l > 0) hash = mod_sub(hash, hashValues[l - 1]);
        return mod_mul(hash, invPowers[l]);
    }
};

int main() {
    string str = "abc";
    Hashing H(str);
    int n = str.length();
    set<ll> unique_hashes;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            unique_hashes.insert(H.getHash(i, j));
        }
    }
    cout << unique_hashes.size() << "\n";
}
