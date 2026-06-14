#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> fa(N,vector<int>(22));
vector<int> dep(N);


// 倍增法求LCA
int lca(int u, int v) {
    // 确保u是深度较大的节点
    if (dep[u] < dep[v]) swap(u, v);
    
    // 第一步：将u提升到与v相同的深度
    for (int i = 20; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    
    // 如果u和v相同，直接返回
    if (u == v) return u;
    
    // 第二步：同时提升u和v，直到它们的父节点相同
    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    
    // 返回LCA
    return fa[u][0];
}