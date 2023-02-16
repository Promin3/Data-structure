//
// Created by kevin on 2023/2/14.
//
#include "AdjGraph.cpp"
#include "stack"

void topsort(adjGraph &g) {
    stack<int> st;
    int indegree[MAXV];
    std::memset(indegree, 0, sizeof(indegree));
    ArcNode *p;
    for (int i = 0; i < g.n; ++i) {
        p = g.adjlist[i].firstarc;
        while (p != nullptr) {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }

    for (int i = 0; i < g.n; ++i)
        if (indegree[i] == 0)
            st.push(i);

    while (!st.empty()) {
        int i = st.top();
        st.pop();
        std::printf("%d ",i);
        p = g.adjlist[i].firstarc;
        while (p != nullptr){
            indegree[p->adjvex]--;
            if(indegree[p->adjvex] == 0)
                st.push(p->adjvex);
            p = p->nextarc;
        }
    }
}