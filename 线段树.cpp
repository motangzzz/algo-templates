#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>

int n;
ll arr[200005];
ll tree[1000000];

void up(int i){
     tree[i]=tree[i<<1]+tree[i<<1|1];
}

void build(int l,int r,int f){
     if(l==r){
          tree[f]=arr[l];
          return;
     }
     int mid=(l+r)>>1;
     build(l,mid,f<<1);
     build(mid+1,r,f<<1|1);
     up(f);
}

ll query(int jl,int jr,int l,int r,int f){
     ll ans=0;
     if(jl<=l&&r<=jr) return tree[f];
     int mid=(l+r)>>1;
     if(jl<=mid) ans+=query(jl,jr,l,mid,f<<1);
     if(jr>mid) ans+=query(jl,jr,mid+1,r,f<<1|1);
     return ans;
}


void code(){
     cin>>n;
     for(int i=1;i<=n;++i) cin>>arr[i];
     build(1,n,1);

}


int main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     int t=1;
     cin>>t;
     while(t--) code();
}