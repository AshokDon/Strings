#include<bits/stdc++.h>
using namespace std;

int main(){
    string s , t;
    cin >> s >> t;
    //KMP
    int n = s.size();
    int m = t.size();
    vector<int> pi(m);
    for(int i = 1 , j = 0 ; i < m ; i++){
        while(j > 0 && t[i] != t[j]) j = pi[j-1];
        if(t[i] == t[j]) j++;
        pi[i] = j;
    }
    for(int i = 0 , j = 0 ; i < n ; i++){
        while(j > 0 && s[i] != t[j]) j = pi[j-1];
        if(s[i] == t[j]) j++;
        if(j == m){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    
}
