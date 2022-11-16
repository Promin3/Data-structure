//
// Created by 朱俊杰 on 2022/11/9.
//
#include "queue"

using namespace std;

struct HTNode {
    char data;
    double weight;
    int parent;
    int leftChild;
    int rightChild;
    bool flag;

    HTNode() {
        parent = leftChild = rightChild = -1;
    }

    HTNode(char d, double w) {
        data = d;
        weight = w;
        parent = leftChild = rightChild = -1;
        flag = true;
    }
};

struct HeapNode {
    double weight;
    int i;

    HeapNode(double weight, int i) : weight(weight), i(i) {}

    bool operator<(const HTNode &s) const {
        return this->weight > s.weight;
    }
};

void CreateHT(HTNode ht[], int n0, char D[], double W[]) {
    priority_queue<HeapNode> qu;
    for (int i = 0; i < n0; ++i) {
        ht[i] = HTNode(D[i], W[i]);
        qu.push(HeapNode(W[i], i));
    }
    for (int i = n0; i < 2 * n0 - 1; ++i) {
        HeapNode p1 = qu.top();
        qu.pop();
        HeapNode p2 = qu.top();
        qu.pop();
        ht[i] = HTNode();
        ht[i].weight = ht[p1.i].weight + ht[p2.i].weight;
        ht[p1.i].parent = i;
        ht[i].leftChild = p1.i;
        ht[p1.i].flag = true;
        ht[p2.i].parent = i;
        ht[i].rightChild = p2.i;
        ht[p2.i].flag = false;
        qu.push(HeapNode(ht[i].weight,i));
    }
}