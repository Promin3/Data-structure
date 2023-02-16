//
// Created by kevin on 2023/2/2.
//
#include "adjGraph.cpp"
#include "queue"

void BFS(adjGraph &g, int v){
    int visited[MAXV];
    std::memset(visited,0, sizeof(visited));
    queue<int> qu;
    cout << v <<" ";
    qu.push(v);
    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        ArcNode *p = g.adjlist[u].firstarc;
        while (p != nullptr){
            if(visited[p->adjvex] != 0){
                cout << p->adjvex << " ";
                qu.push(p->adjvex);
                visited[p->adjvex] = 0;
            }
            p = p->nextarc;
        }
    }
}
