//
// Created by kevin on 2023/2/1.
//
#include "AdjGraph.cpp"

int visited[MAXV];
void DFS(adjGraph &g,int v){
    cout << v << " ";
    visited[v] = 1;
    ArcNode *p = g.adjlist[v].firstarc;
    while (p != nullptr){
        int w = p->adjvex;
        DFS(g,w);
        p = p->nextarc;
    }
}

