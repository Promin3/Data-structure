//
// Created by kevin on 2023/2/1.
//

#include "iostream"

using namespace std;
const int MAXV = 1000;
const int INF = 0x3f3f3f3f;

struct ArcNode {
    int adjvex; // adjoin vertex
    int weight; // edge weight
    ArcNode *nextarc;
};

struct HNode {
    string info;
    ArcNode *firstarc;
};

class adjGraph {
public:
    HNode adjlist[MAXV];
    int n, e;

    adjGraph() {
        for (int i = 0; i < MAXV; ++i) {
            adjlist[i].firstarc = nullptr;
        }
    }

    ~adjGraph() {
        ArcNode *p, *pre;
        for (int i = 0; i < n; ++i) {
            pre = adjlist[i].firstarc;
            if (pre != nullptr) {
                p = pre->nextarc;
                while (p != nullptr) {
                    delete pre;
                    pre = p;
                    p = p->nextarc;
                }
                delete pre;
            }
        }
    }

    void CreateAdjGraph(int a[][MAXV], int n, int e) {
        ArcNode *p;
        this->n = n;
        this->e = e;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (a[i][j] != 0 && a[i][j] != INF) {// 说明存在边
                    p = new ArcNode();
                    p->adjvex = j;
                    p->weight = a[i][j];
                    p->nextarc = adjlist[i].firstarc;
                    adjlist[i].firstarc = p;
                }
            }
        }
    }

    void DispAdjGraph()            //输出图的邻接表
    {
        ArcNode *p;
        for (int i = 0; i < n; i++)        //遍历每个头结点
        {
            printf("   [%d]", i);
            p = adjlist[i].firstarc;        //p指向第一个邻接点
            if (p != nullptr) printf("→");
            while (p != nullptr)            //遍历第i个单链表
            {
                printf(" (%d,%d)", p->adjvex, p->weight);
                p = p->nextarc;        //p移向下一个邻接点
            }
            printf("\n");
        }
    }

};

//int main()
//{  adjGraph G;
//    int n=5,e=5;
//    int A[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
//                       {INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};
//    G.CreateAdjGraph(A,n,e);
//    cout << "图的邻接表:\n"; G.DispAdjGraph();
//    cout << "销毁图\n";
//    return 0;
//}
