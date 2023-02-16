//
// Created by kevin on 2023/2/1.
//

//一个含有n个顶点e条边的图采用邻接表存储，设计以下算法：
//（1）该图为无向图，求其中顶点v的度。
//（2）该图为有向图，求该图中顶点v的出度和入度。

#include "AdjGraph.cpp"
#include "vector"
int degree1(adjGraph &g ,int v){
    int ans;
    ArcNode *p;
    p = g.adjlist[v].firstarc;
    while (p != nullptr){
        p = p->nextarc;
        ans ++;
    }
    return ans;
}

vector<int> degree2(adjGraph &g, int v) {
    vector<int> ans = {0, 0};
    ArcNode *p = g.adjlist[v].firstarc;
    while (p != nullptr) {
        ans[0]++;
        p = p->nextarc;
    }
    for (int i = 0; i < g.n; ++i) {
        p = g.adjlist[i].firstarc;
        while (p != nullptr){
            if(p->adjvex == v){
                ans[1]++;
                break;
            }
            p = p->nextarc;
        }
    }
    return ans;
}