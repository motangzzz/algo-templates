#include<bits/stdc++.h>
using namespace std;
#define vi  vector<int>

int main(){
     int n;
     cin>>n;
     vi arr(n);
     for(auto &x:arr) cin>>x;
     stack<int> sta;
     vi ans(n);
     for(int i=0;i<n;++i){
          while(sta.size()&&arr[i]>arr[sta.top()]){
               ans[sta.top()]=i+1;
               sta.pop();
          }
          sta.push(i);
     }
}