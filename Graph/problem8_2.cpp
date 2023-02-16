//
// Created by kevin on 2023/1/30.
//


//一个含有n个顶点e条边的图采用邻接矩阵g存储，设计以下算法：
//（1）该图为无向图，求其中顶点v的度。
//（2）该图为有向图，求该图中顶点v的出度和入度。

#include "MatGraph.cpp"
#include "vector"

int degree1(MatGraph &g, int v) {
    int d = 0;
    for (int i = 0; i < g.n; ++i) {
        if (g.edges[v][i] != 0 && g.edges[v][i] != INF)
            d++;
    }
    return d;
}


vector<int> degree2(MatGraph &g, int v) {
    vector<int> ans = {0, 0};
    for (int i = 0; i < g.n; ++i) {
        if (g.edges[v][i] != 0 && g.edges[v][i] != INF)
            ans[0]++;
    }
    for (int j = 0; j < g.n; ++j) {
        if (g.edges[j][v] != 0 && g.edges[j][v] != INF)
            ans[1]++;
    }
    return ans;
}
//
//int main() {
//    MatGraph g1, g2;
//    int n = 5, e = 8;
//    int a[MAXV][MAXV] = {{0, 1, 0, 1, 1},
//                         {1, 0, 1, 1, 0},
//                         {0, 1, 0, 1, 1},
//                         {1, 1, 1, 0, 1},
//                         {1, 0, 1, 1, 0}};
//    g1.CreateMatGraph(a, n, e);
//    printf("图G1(无向图)\n");
//    g1.DisMatGraph();
//    printf("求解结果\n");
//    for (int i = 0; i < g1.n; i++)
//        printf("  顶点%d的度: %d\n", i, degree1(g1, i));
//
//    n = 5;
//    e = 5;
//    int b[MAXV][MAXV] = {{0,   8,   INF, 5,   INF},
//                         {INF, 0,   3,   INF, INF},
//                         {INF, INF, 0,   INF, 6},
//                         {INF, INF, 9,   0,   INF},
//                         {INF, INF, INF, INF, 0}};
//    g2.CreateMatGraph(b, n, e);
//    printf("图G2(有向图)\n");
//    g2.DisMatGraph();
//    printf("求解结果\n");
//    for (int i = 0; i < g2.n; i++) {
//        vector<int> ans = degree2(g2, i);
//        printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",
//               i, ans[0], ans[1], ans[0] + ans[1]);
//    }
//    return 0;
//}
