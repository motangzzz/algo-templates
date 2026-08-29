#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x,y;

int exgcd(ll m,ll n){
     if(n==0){
          x=1;
          y=0;
          return m;
     }
     ll ans=exgcd(n,m%n);
     ll dx=x;
     x=y;
     y=dx-m/n*y;
     return ans;
}

//待完善
int exgcd1(int m,int n,int& x,int& y){
     if(n==0){
          x=1;
          y=0;
          return m;
     }
     int r=exgcd1(n,m%n,y,x);
     y-=m/n*x;
     return r;
}