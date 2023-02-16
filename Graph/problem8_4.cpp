//
// Created by kevin on 2023/2/2.
//
#include "AdjGraph.cpp"

int visited[MAXV];

void DFS(adjGraph &g, int v) {
    visited[v] = 1;
    ArcNode *p = g.adjlist[v].firstarc;
    while (p != nullptr) {
        if (visited[p->adjvex] != 1) {
            DFS(g, p->adjvex);
        }
        p = p->nextarc;
    }
}

bool connect(adjGraph &g){
    DFS(g,0);
    for (int i = 0; i < g.n; ++i) {
        if(visited[i] == 0)
            return false;
    }
    return true;
}