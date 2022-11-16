//
// Created by 朱俊杰 on 2022/11/6.
//
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"
#include <queue>

int kcount3(BTree &bt, int k) {
    if (k < 1) return 0;
    queue<BTreeNode *> qu;
    int curl = 1;
    qu.push(bt.rootnode);
    while (!qu.empty()){
        if(curl == k)
            return qu.size();
        int n = qu.size();
        for (int i = 0; i < n; ++i) {
            BTreeNode *p = qu.front();
            qu.pop();
            if(p->leftchild != nullptr)
                qu.push(p->leftchild);
            if(p->rightchild != nullptr)
                qu.push(p->rightchild);
        }
        curl++;
    }
    return 0;
}