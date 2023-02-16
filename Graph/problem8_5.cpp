//
// Created by kevin on 2023/2/2.
//
#include "AdjGraph.cpp"

int visited[MAXV];

bool hasPath(adjGraph &g, int u, int v) {
    visited[u] = 1;
    ArcNode *p = g.adjlist[u].firstarc;
    while (p != nullptr) {
        if (p->adjvex == v)return true;
        else if (visited[p->adjvex] == 0) {
            if (hasPath(g, p->adjvex, v))return true;
        }
        p = p->nextarc;
    }
    return false;
}