
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//if the string contains only lowercase letters the p = 31 otherwise p = 53
//if the string contains only lowercase letters the m = 1e9+9 otherwise m = 1e9+7
//this is called polynomial rolling hash function
//the rate of collision is very low
ll Compute_hash(string s){
    ll p = 31;
    ll m = 1e9+9;
    ll hash_value = 0;
    ll p_pow = 1;
    for(char c : s){
        hash_value = (hash_value + (c-'a'+1)*p_pow)%m;
        p_pow = (p_pow*p)%m;
    }
    return hash_value;
}
int main(){
    string s;
    cin >> s;
    int n = s.length();
    ll Hash_Value = Compute_hash(s);
}
