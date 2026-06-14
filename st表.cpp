#include<bits/stdc++.h>
using namespace std;
#define vi  vector<int>
#define vvi vector<vector<int>>

int st[200005][20],lg2[200005];

void code(){
     int n,q;
     cin>>n>>q;
     vi arr(n+1);
     for(int i=1;i<=n;++i) cin>>arr[i];
     int len=log2(n)+1;
     for(int i=1;i<=n;++i) st[i][0]=arr[i];
     for(int i=1;i<len;++i){
          for(int j=1;j+(1<<i)<=n+1;++j){//注意边界
               st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
          }
     }
     while(q--){
          int t1,t2;
          cin>>t1>>t2;
          int pow=log2(t2-t1+1);
          cout<<max(st[t1][pow],st[t2-(1<<pow)+1][pow])<<'\n';//注意边界
     }
}