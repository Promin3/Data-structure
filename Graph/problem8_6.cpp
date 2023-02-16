//
// Created by kevin on 2023/2/2.
//
#include "AdjGraph.cpp"
#include "vector"

int visited[MAXV];

void findPath1(adjGraph &g, int u, int v, vector<int> path) {
    visited[u] == 1;
    path.push_back(u);
    if(u == v){
        for (auto p : path) {
            cout << p << " ";
        }
        cout << endl;
        return;
    }
    ArcNode *p = g.adjlist[u].firstarc;
    while (p != nullptr){
        if(visited[p->adjvex] == 0){
            findPath1(g,p->adjvex,v,path);
        }
        p = p->nextarc;
    }
}

void findPath(adjGraph &g, int u, int v) {
    vector<int> path;
    std::memset(visited, 0, sizeof(visited));
    findPath1(g, u, v, path);
}