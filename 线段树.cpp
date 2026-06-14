#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>

int n;
ll arr[200005];
ll tree[1000000];
ll add[1000000];//懒更新数组

void lazy(int i,ll jv,int len){
     add[i]+=jv;
     tree[i]+=len*jv;
}

void up(int i){
     tree[i]=tree[i<<1]+tree[i<<1|1];
}

void down(int i,int ln,int rn){
     if(add[i]!=0){
          lazy(i<<1,add[i],ln);
          lazy(i<<1|1,add[i],rn);
          add[i]=0;
     }
}

void build(int l,int r,int f){
     add[f]=0;
     if(l==r){
          tree[f]=arr[l];
          return;
     }
     int mid=(l+r)>>1;
     build(l,mid,f<<1);
     build(mid+1,r,f<<1|1);
     up(f);
}

ll query(int jl,int jr,int l,int r,int i){
     ll ans=0;
     if(jl<=l&&r<=jr) return tree[i];
     int mid=(l+r)>>1;
     down(i,mid-l+1,r-mid);
     if(jl<=mid) ans+=query(jl,jr,l,mid,i<<1);
     if(jr>mid) ans+=query(jl,jr,mid+1,r,i<<1|1);
     return ans;
}

void update(int jl,int jr,ll jv,int l,int r,int i){
     if(jl<=l&&r<=jr){
          lazy(i,jv,r-l+1);
          return;
     }
     int mid=(l+r)>>1;
     down(i,mid-l+1,r-mid);
     if(jl<=mid) update(jl,jr,jv,l,mid,i<<1);
     if(jr>mid) update(jl,jr,jv,mid+1,r,i<<1|1);
     up(i);
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