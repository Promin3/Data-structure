//
// Created by 朱俊杰 on 2022/11/6.
//
#include <queue>
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

int kcount2(BTree &bt, int k) {
    int cnt = 0;
    queue<BTreeNode *> qu;
    int curl = 1;
    BTreeNode *last = bt.rootnode, *p, *q;
    qu.push(bt.rootnode);
    while (!qu.empty()) {
        if (curl > k)
            return cnt;
        p = qu.front();
        qu.pop();
        if (curl == k)
            cnt++;
        if (p->leftchild != nullptr) {
            q = p->leftchild;
            qu.push(q);
        }
        if (p->rightchild != nullptr) {
            q = p->rightchild;
            qu.push(q);
        }
        if (p == last) {
            last = q;
            curl++;
        }
    }
    return cnt;
}