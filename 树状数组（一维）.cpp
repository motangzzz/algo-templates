#include<bits/stdc++.h>
using namespace std;
using ll = long long;


//适用于区间求和，区间求积，区间异或和
//即满足结合律和可差分的运算都可以使用树状数组


//1.单点修改，区间查询
ll tree[200005];
ll arr[200005];
ll tree1[200005];
ll tree2[200005];
ll n;

inline ll lowbit(ll n){
     return n&-n;
}

void build1(){
     for(ll i=1;i<=n;++i){
          tree[i]+=arr[i];
          ll j=i+lowbit(i);
          if(j<=n) tree[j]+=tree[i];
     }
}

void add1(ll idx,ll tp){
     while(idx<=n){
          tree[idx]+=tp;
          idx+=lowbit(idx);
     }
}

ll sum1(ll r){
     ll ans=0;
     while(r){
          ans+=tree[r];
          r-=lowbit(r);
     }
     return ans;
}

ll query1(ll l,ll r){
     return sum1(r)-sum1(l-1);
}


//2.范围修改，单点查询
//利用差分数组实现

void add2(ll l,ll r,ll val){
     while(l<=n){
          tree[l]+=val;
          l+=lowbit(l);
     }
     r++;
     while(r<=n){
          tree[r]-=val;
          r+=lowbit(r);
     }
}

void build2(){
     for(ll i=1;i<=n;++i) add2(i,i,arr[i]);
}

ll query2(ll idx){
     ll ans=0;
     while(idx){
          ans+=tree[idx];
          idx-=lowbit(idx);
     }
     return ans;
}

//3。范围修改，范围查询
//其实就是线段树，只不过用树状数组实现

void add3(ll* tre,ll tp,ll val){
     while(tp<=n){
          tre[tp]+=val;
          tp+=lowbit(tp);
     }
}

ll sum3(ll* tre,ll r){
     ll ans=0;
     while(r){
          ans+=tre[r];
          r-=lowbit(r);
     }
     return ans;
}

void build3(){
     for(ll i=1;i<=n;++i){
          add3(tree1,i,arr[i]);
          add3(tree1,i+1,-arr[i]);
          add3(tree2,i,(i-1)*arr[i]);
          add3(tree2,i+1,-(i*arr[i]));
     }
}

void update(ll l,ll r,ll val){
     add3(tree1,l,val);
     add3(tree1,r+1,-val);
     add3(tree2,l,(l-1)*val);
     add3(tree2,r+1,-r*val);
}

ll query3(ll l,ll r){
     return r*sum3(tree1,r)-(l-1)*sum3(tree1,l-1)-sum3(tree2,r)+sum3(tree2,l-1);
}

void code(){
     cin>>n;
     for(ll i=1;i<=n;++i) cin>>arr[i];
}

int main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     int t=1;
     //cin>>t;
     while(t--) code();                 
} 