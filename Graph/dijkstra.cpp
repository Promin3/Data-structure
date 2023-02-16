//
// Created by kevin on 2023/2/8.
//
#include "MatGraph.cpp"
#include "vector"

using namespace std;

void DispAllPath(int dist[], int path[],int s[], int v, int n){
    for (int i = 0; i < n; ++i)
        if (s[i] == 1 && i != v) {
            printf("从%d到%d的最短距离为%d，路径：", v, i, dist[i]);
            vector<int> apath;
            apath.push_back(i);
            int pre = path[i];
            while (pre != v) {
                apath.push_back(pre);
                pre = path[pre];
            }
            printf("%d", v);
            for (int j = apath.size() - 1; j >= 0; --j)
                printf("->[%d]", apath[j]);
            printf("\n");
        }
        else
            printf("%d到%d没有路径",v,i);
}
void dijkstra(MatGraph &g, int v) {
    int dist[MAXV];
    int path[MAXV];
    int s[MAXV];
    for (int i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        s[i] = 0;
        if (dist[i] != 0 && dist[i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    s[v] = 1;
    int mindis,u = -1;
    for (int i = 0; i < g.n - 1; ++i) { // 循环向s中添加n - 1个顶点
        mindis = INF;
        for (int j = 0; j < g.n; ++j)
            if (s[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }
        s[u] = 1;

        for (int j = 0; j < g.n; ++j)  // 修改不在s中顶点的距离
            if (s[j] == 0 && g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
    }
    DispAllPath(dist,path,s,v,g.n);
}