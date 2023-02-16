//
// Created by kevin on 2023/2/7.
//


/**
 * 改进克鲁斯卡尔算法的时间复杂度为O(elog_2e)。由于与n无关，所以克鲁斯卡尔算法特别适合于稀疏图求最小生成树。
 */
#include "MatGraph.cpp"
#include "vector"

int parent[MAXV];
int rak[MAXV];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]); // 路径压缩
    return parent[x];
}


void Union(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry)
        return;
    if (rak[rx] < rak[ry])
        parent[rx] = ry;
    else if (rak[rx] == rak[ry]) {
        rak[rx]++;
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
    }
}


struct Edge {
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge &rhs) const { // rhs right hand side 右操作数
        return w < rhs.w;
    }
};

void kruskal_pro(MatGraph &g) {
    vector<Edge> e;
    // 利用矩阵的上三角构造 向量e
    for (int i = 0; i < g.n; ++i)
        for (int j = i + 1; j < g.n; ++j)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
                e.push_back(Edge(i, j, g.edges[i][j]));
    sort(e.begin(), e.end());
    init(g.n);// vset[maxv]

    int k = 1;// 增加边 编号
    int j = 0;// vector 编号
    while (k < g.n) {
        int u1 = e[j].u;
        int v1 = e[j].v;
        int sn1 = find(u1);
        int sn2 = find(v1);
        if (sn1 != sn2) {
            cout << "边（" << u1 << "," << v1 << "),权为" << e[j].w << endl;
            k++;
            Union(sn1, sn2);
        }
        j++;
    }
}

