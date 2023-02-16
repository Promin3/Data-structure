//
// Created by kevin on 2023/2/3.
//

#include "AdjGraph.cpp"
#include "queue"

struct QNode {
    int v;
    int dis;

    QNode(int v, int dis) : v(v), dis(dis) {}

    QNode() {}
};

int shortDis(adjGraph &g, int u, int v) {
    queue<QNode> qu;
    qu.push(QNode(u, 0));
    int visited[MAXV];
    std::memset(visited, 0, sizeof(visited));
    visited[u] = 1;
    while (!qu.empty()) {
        QNode n = qu.front();
        qu.pop();
        if (n.v == v)
            return n.dis;

        ArcNode *p = g.adjlist[n.v].firstarc;
        while (p != nullptr) {
            if (visited[p->adjvex] == 0) {
                qu.push(QNode(p->adjvex, n.dis + 1));
                visited[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
    return INF;
}