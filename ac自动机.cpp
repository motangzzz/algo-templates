#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN=1000005;

//直通表
int tree[MAXN][26]={};

//fail指针
int fail[MAXN]={};

//每个字符串的结尾节点
int last[MAXN]={};

//收集词频的数组
int times[MAXN]={};

//当前节点的数量
int cnt=0;

void insert(int i,string& s){
     int u=0;
     for(auto x:s){
          int cur=x-'a';
          if(tree[u][cur]==0) tree[u][cur]=++cnt;
          u=tree[u][cur];
     }
     last[i]=u;
}

void setFail(){
     queue<int> q;
     for(int i=0;i<26;++i){
          if(tree[0][i]!=0) q.push(tree[0][i]);
     }
     while(q.size()){
          int u=q.front();
          q.pop();
          for(int i=0;i<26;++i){
               if(tree[u][i]==0) tree[u][i]=tree[fail[u]][i];
               else {
                    q.push(tree[u][i]);
                    fail[tree[u][i]]=tree[fail[u]][i];
               }
          }
     }
}
