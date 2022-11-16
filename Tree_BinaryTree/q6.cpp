//
// Created by 朱俊杰 on 2022/11/9.
//

#include <queue>
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

int width(BTreeNode *p) {
    int width = 0;
    queue<BTreeNode *> qu;
    qu.push(p);
    while (!qu.empty()) {
        int n = qu.size();
        width = max(width,n);
        // 处理同一层的结点
        for (int i = 0; i < n; ++i) {
            BTreeNode * first = qu.front();
            qu.pop();
            if (first->leftchild != nullptr)
                qu.push(first->leftchild);

            if (first->rightchild != nullptr)
                qu.push(first->rightchild);
        }
    }
    return width;
}