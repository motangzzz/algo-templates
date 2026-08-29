#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

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

//邻接矩阵，建立反图
vi dis[MAXN];

//边界数组，记录每个串匹配的位置
vi idx[MAXN];

//把每个串建立自动机
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
               //如果当前节点的该分支没有儿子，那么继承父亲节点的直通
               if(tree[u][i]==0) tree[u][i]=tree[fail[u]][i];
               else {
                    q.push(tree[u][i]);
                    //找父亲的直达
                    fail[tree[u][i]]=tree[fail[u]][i];
               }
          }
     }
}

//记录每个串在模式串里面出现了几次

//1.建立反图

void addEdge(int u,int v){
     dis[u].push_back(v);
}

void buildGraph(){
     for(int i=0;i<=cnt;++i){
          if(i||fail[i]) addEdge(fail[i],i);
     }
}

//2.递归得到计数

ll cul(int i){
     ll sum=times[i];
     for(auto x:dis[i]) sum+=cul(x);
     times[i]=sum;
     return sum;
}