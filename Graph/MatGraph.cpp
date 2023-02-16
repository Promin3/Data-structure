#include <iostream>

const int MAXV = 100;
const int INF = 0x3f3f3f3f;
using namespace std;

// 图的邻接矩阵存储方法
class MatGraph {
public:
    int edges[MAXV][MAXV];  //邻接矩阵数组
    int n, e;
    string vexs[MAXV]; // 存放顶点信息

    void CreateMatGraph(int a[][MAXV], int n, int e) {
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->edges[i][j] = a[i][j];
            }
        }
    }

    void DisMatGraph() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (this->edges[i][j] == INF)
                    printf("%4s", "∞");
                else
                    printf("%2d", edges[i][j]);
            }
            printf("\n");
        }
    }
};


