//Fast hash calculation of substrings of given string
//Given a string s of length  n , consisting only of lowercase English letters, find the number of different 
//substrings in this string.



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 9;
ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%m*x%m*a%m) % m;
    }
    else{
        return (x*x) % m;
    }
}
ll inverse(ll a, ll m){
    return power(a,m-2);
}
ll Count_Unique_Substrings(string const &s){
    int n = s.size();
    const int p = 31;
    
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for(int i = 1 ; i < n ; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
        

    }
    vector<ll> h(n+1,0);
    for(int i = 0 ; i < n ; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        //cout<<h[i+1]<<" ";
    }
    ll cnt = 0;
    for(int l = 1 ; l <= n ; l++){
        set<ll>s;
        for(int  i = 0 ; i <= n - l ; i++){
           // cout<<i<<" "<<i+l<<" "<<h[i+l]<<endl;
            ll cur_hash = (h[i+l] + m - h[i]) % m;
            cur_hash = (cur_hash * inverse(p_pow[i],m)) % m;
            s.insert(cur_hash);
        }
        cnt += s.size();
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = Count_Unique_Substrings(s);
    cout<<ans<<endl;
}
