//
// Created by kevin on 2023/2/3.
//

#include "AdjGraph.cpp"
#include "queue"

int shortdis2(adjGraph &g, int u, int v){
    queue<int> qu;
    qu.push(u);
    int visited[MAXV];
    std::memset(visited,0, sizeof(visited));
    visited[u] = 1;
    int ans = 0;
    while (!qu.empty()) {
        int n = qu.size();
        for (int i = 0; i < n; ++i) {
            int k = qu.front();
            qu.pop();
            if(k == v)
                return ans;

            ArcNode *p = g.adjlist[k].firstarc;
            while(p != nullptr) {
                if(visited[p->adjvex] == 0){
                    visited[p->adjvex] = 1;
                    qu.push(p->adjvex);
                }
                p = p->nextarc;
            }
        }
        ans ++;
    }
    return INF;
}
