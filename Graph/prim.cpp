//
// Created by kevin on 2023/2/7.
//


/**
 * 普里姆算法中有两重for循环，所以时间复杂度为O(n2)，其中n为图的顶点个数。
由于与e无关，所以普里姆算法特别适合于稠密图求最小生成树。

 */
#include "MatGraph.cpp"

void prim(MatGraph &g, int v) {
    int closest[MAXV];
    int lowcost[MAXV]; // 该数组表示顶点 i 属于集合U 还是 V-U 如果是 v-u，则数值表示距离 u集合的最短长度，如果是 U，则数值为0，将该数值制0，表示将点归入u集合
    for (int i = 0; i < g.n; ++i) {
        closest[i] = v;
        lowcost[i] = g.edges[v][i];
    }
    for (int i = 1; i < g.n; ++i) { // 找出 n-1 个节点
        int min = INF;
        int k = -1;
        // 找到最小的k
        for (int j = 0; j < g.n; ++j) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                k = j;
                min = lowcost[j];
            }
        }
        cout << "边（" << closest[k] << "," << k << "),权为" << min << endl;
        // 将k节点归入u集合
        lowcost[k] = 0;
        //
        for (int j = 0; j < g.n; ++j) {
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
}