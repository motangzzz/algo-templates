#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vi  vector<int>
#define vvi vector<vi>

int n,k;

int main(){
     cin>>n>>k;
     vi v(n),w(n);
     for(auto &x:v) cin>>x;
     for(auto &x:w) cin>>x;
     vi dp(k+1,0);
     for(int i=0;i<n;++i){
          for(int j=k;j>=w[i];--j){
               dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
          }
     }
     cout<<dp[k];
}