#include<bits/stdc++.h>
using namespace std;

int n,cnt;
int fa[200005],sz[200005];

void build(int n){
     for(int i=1;i<=n;++i){
          fa[i]=i;
          sz[i]=1;
     }
}

int find(int r){
     if(r!=fa[r]) fa[r]=find(fa[r]);
     return fa[r];
}

void unite(int r1,int r2){
     int dx=find(r1);
     int dy=find(r2);
     if(dx!=dy){
          sz[dx]+=sz[dy];
          fa[dy]=dx;
          cnt--;
     }
}

int issame(int r1,int r2){
     return find(r1)==find(r2);
}