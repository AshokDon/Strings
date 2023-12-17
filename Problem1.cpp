//q:search for duplicate string in an array of strings
//given a list of strings si, each no longer then m characters, find all the duplicate strings and divide them into groups.
//the strings are given in an array of size n, where n is at most 100,000 and m is at most 50.
//for example, if the input is
//4
//aba
//bbb
//aba
//xyz
//bbb
//the output is
//[[0,2],[1,4],[3]]


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
vector<vector<int>> group_identical_strings(vector<string> const &s){
    int n = s.size();
    vector<pair<long long, int>>hashes(n);
    for(int i = 0 ; i < n ; i++){
        hashes[i] = {Compute_hash(s[i]), i};

    }
    sort(hashes.begin(), hashes.end());
    vector<vector<int>>groups;
    for(int i = 0 ; i < n ; i++){
        if(i == 0 || hashes[i].first != hashes[i-1].first){
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    vector<vector<int>>ans = group_identical_strings(s);
}
