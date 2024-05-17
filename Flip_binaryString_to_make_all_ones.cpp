
//PROBLEM : https://codeforces.com/contest/1955/problem/E

#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 1e6 + 5;
const double pi = acos(-1.0);
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


void Don(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    int k;
    //try out all the k's from n to find the maximum possible k need to flip all k consecutive 0's to 1's
    for(k = n ; k >= 0 ; k--){
        //copy the string to a vector so that we can work on dummy t vector for every k
        vector<int>t(n) , end(n+1);
        for(int i = 0 ; i < n; i++){
            t[i] = s[i] - '0';
        }
        //end[i] = 1 means that the i-th element is flipped
        int cnt = 0; // cnt is the number of flips needed to flip all k consecutive 0's to 1's
        for(int i = 0 ; i < n; i++){// i is the starting index of the k consecutive 0's
            cnt-=end[i];//if end[i] = 1 then we need to flip the i-th element
            t[i] ^= (cnt & 1);//if cnt is odd then we need to flip the i-th element
            
            if(t[i] == 0){//if the i-th element is 0 then we need to flip all k consecutive 0's to 1's
                
                if(i + k <= n){//if the k consecutive 0's are present in the string
                    cnt++;//increment the cnt as we need to flip the i-th element
                    end[i+k] = 1;//end[i+k] = 1 means that the i+k-th element is flipped
                    t[i] = 1;//flip the i-th element
                    
                }
                else{//if the k consecutive 0's are not present in the string
                    break;//break the loop as we can't flip all k consecutive 0's to 1's
                }
            }

        }
        
        //cout<<endl;
        if(*min_element(t.begin(),t.end()) == 1){

            cout<<k<<endl;
            return;
        }
    }
    

}



int main(){
    fast_io;
    ll t;
    cin >> t;
    while(t--){
        Don();
    }
}
