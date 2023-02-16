//
// Created by kevin on 2023/2/9.
//

#include "MatGraph.cpp"
#include "vector"

void Dispath(int A[][MAXV], int path[][MAXV], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (A[i][j] != INF && i != j)    //若顶点i和j之间存在路径
            {
                vector<int> apath;    //存放一条i到j的最短逆路径
                printf("顶点 % d到 % d的最短路径长度:%d\t路径:", i, j, A[i][j]);
                apath.push_back(j);    //路径上添加终点j
                int pre = path[i][j];
                while (pre != i)        //路径上添加中间点
                {
                    apath.push_back(pre);    //顶点pre加入到路径中
                    pre = path[i][pre];
                }
                cout << i;              //输出起点i
                for (int k = apath.size() - 1; k >= 0; k--)
                    printf("->%d", apath[k]);  //反向输出路径上的其他顶点
                printf("\n");
            }
        }

}

void floyd(MatGraph &g) {
    int A[MAXV][MAXV];
    int path[MAXV][MAXV];
    for (int i = 0; i < g.n; ++i)
        for (int j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            if (g.[i][j] != 0 && g[i][j] < INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }

    for (int k = 0; k < g.n; ++k)
        for (int i = 0; i < g.n; ++i)
            for (int j = 0; j < g.n; ++j)
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
    Dispath(A, path, g.n);
}