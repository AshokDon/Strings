#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define F first
#define S second
#ifndef ONLINE_JUDGE
/*============================Run Debug code =============================*/
#define debug(x) cerr << #x<<" " ; _print(x); cerr<<endl;
#else
#define debug(x)
#endif


#define FOR(i,a,b) for(int i = a ; i < b ; i++)


using namespace std;
const int mod = (int)1e9 + 9;
vector<ll>bit;


/*====================================================== debugging templates ==============================================*/
template<class T>void _print(T a){cerr << a;}
template<class T> void _print(vector<T>v1){cerr<<"[";for(T i : v1)cerr<<i<<" ";cerr<<"]";}
template<class T> void _print(set<T>st){cerr <<"[" ; for(T i : st)cerr<<i<<" ";cerr<<"]";}
template<class T, class U> void _print(map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}
template<class T, class U> void _print(unordered_map<T,U>mp){for(T i : mp){cerr << i.F <<" : "<<i.S;}}


/*====================================================================MATHS================================================*/

ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%mod*x%mod*a%mod) % mod;
    }
    else{
        return (x*x) % mod;
    }
}
ll inverse(ll a){
    return power(a,mod-2);
}
// NcR -> Primes ->

/*======================================================================================================================*/

string shortestPalindrome(string s) {
    ll n = s.size(); 
    vector<ll> h(n + 1, 0);
    vector<ll> rh(n + 1, 0);
    vector<ll> p_pow(n + 1);
    ll p = 31;
    p_pow[0] = 1;

    // Precompute powers of p modulo mod
    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }
    
    // Compute forward hash
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
    }
    //
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        rh[j + 1] = (rh[j] + (s[i] - 'a' + 1) * p_pow[j]) % mod;
    }
    //a a c e c a a a
    //1 2 3 4 5 6 7 8
    //a a a c e c a a
    //1 2 3 4 5 6 7 8
    //
    ll high;
    int j = 0;
    for(int i = n ; i > 0 ; i --){
        ll low = 1;
        high = i;
        ll mid = (low + high) >> 1;
    
        ll fp,sp;
        if(high % 2 == 1){
            
            fp = h[mid-1];
            ll x = j + (mid-1);

            sp = (rh[x] + mod - rh[j]) % mod;
            sp = (sp * inverse(p_pow[j]))%mod;
        }
        else{
            fp = h[mid];
            ll x = j + (mid);
            sp = (rh[x] + mod - rh[j]) % mod;
            sp = (sp * inverse(p_pow[j]))%mod;
        }
        j++;
        if(sp == fp){
            break;
        }
    }
    string need;
    high--;
    for(int i = n - 1; i > high; i--) {
        need += s[i];
    }
    s = need + s;
    return s;
}




void Don() {
    string s;
    cin >> s;
    cout << shortestPalindrome(s);
}



int main(){
    #ifndef ONLINE_JUDGE

    freopen("Error.txt","w",stderr);
    #endif
    fast_io;
    ll t;
    cin >> t;

    while(t--)Don();
}

