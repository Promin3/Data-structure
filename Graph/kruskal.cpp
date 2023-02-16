//
// Created by kevin on 2023/2/7.
//

/**
 *
 */
#include "MatGraph.cpp"
#include "vector"

struct Edge {
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge &rhs) const { // rhs right hand side 右操作数
        return w < rhs.w;
    }
};

void kruskal(MatGraph &g) {
    int vset[MAXV];
    vector<Edge> e;
    for (int i = 0; i < g.n; ++i)
        for (int j = i + 1; j < g.n; ++j)
            if (g.edges[i][j] != 0 && g.edges != INF)
                e.push_back(Edge(i, j, g.edges[i][j]));
    sort(e.begin(), e.end());
    for (int i = 0; i < g.n; ++i)
        vset[i] = i;
    int k = 1;
    int j = 0;
    while (k < g.n) {
        int u1 = e[j].u;
        int v1 = e[j].v;
        int sn1 = vset[u1];
        int sn2 = vset[v1];
        if (sn1 != sn2) {
            k++;
            cout << "边（" << u1 << "," << v1 << ") ,权为" << e[j].w << endl;
            for (int i = 0; i < g.n; ++i)
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }
        j++;
    }


}