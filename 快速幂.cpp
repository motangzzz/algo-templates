#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod=1e9+7;

ll qpow(ll m,ll n){
     ll ans=1;
     ll x=m%mod;
     while(n){
          if(n&1){
               ans=(ans*x)%mod;
          }
          x=(x*x)%mod;
          n>>=1;
     }
     return ans;
}