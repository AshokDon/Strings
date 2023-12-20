//Rabin-Karp algorithm 
/*

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 9;
int main(){
    int N ;
    cin >> N;
    
    while(N--){
        ll T;
        cin >> T;
        string s , t;
        cin >> t ;
        cin >> s;
        //cout<<T<<" "<<s<<" "<<t<<endl;
        ll n = s.size();
        ll m = t.size();
        ll p = 31;
        vector<ll> p_pow(max(n,m));
        p_pow[0] = 1;
        ll x = p_pow.size();
        for(int i = 1  ; i < x ; i++){
            p_pow[i] = (p_pow[i-1] * p) % mod;
        }
        vector<ll> h(n+1,0);
        for(int i = 0 ; i < n ; i++){
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
            
        }
        ll h_s = 0;
        for(int i = 0 ; i < m ; i++){
            h_s = (h_s + (t[i] - 'a' + 1) * p_pow[i]) % mod;
            
        }
        vector<ll> occurences;
        for(int i = 0 ; i + m - 1 < n ; i++){
            ll cur_h = (h[i+m] + mod - h[i]) % mod;
            if(cur_h == (h_s * p_pow[i]) % mod){
                occurences.push_back(i);
            }
        }
        if(occurences.size() == 0){
            cout<<"\n";
            continue;
        }
        for(auto &it : occurences){
            cout<<it<<"\n";
        }
        
 
    }
 
} 
