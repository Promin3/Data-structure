
//
// Created by 朱俊杰 on 2022/11/9.
//

#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"
#include <cstddef>
#include "queue"

bool IsComplete(BTreeNode *root) {
    //1.树为空，返回错误
    if (root == NULL) {
        return false;
    }
    //2.树不为空
    queue<BTreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        BTreeNode *top = q.front();
        //2.1如果该节点两个孩子都有，则直接pop
        if (top->leftchild && top->rightchild) {
            q.pop();
            q.push(top->leftchild);
            q.push(top->rightchild);
        }
        //2.2如果该节点左孩子为空，右孩子不为空，则一定不是完全二叉树
        if (top->leftchild == NULL && top->rightchild) {
            return false;
        }
        //2.3如果该节点左孩子不为空，右孩子为空或者该节点为叶子节点，则该节点之后的所有结点都是叶子节点
        if ((top->leftchild && top->rightchild == NULL) || (top->leftchild == NULL && top->rightchild == NULL)) {
            if (NULL != top->leftchild && NULL == top->rightchild) {
                q.push(top->leftchild);
            }
            q.pop(); //则该节点之后的所有结点都是叶子节点
            while (!q.empty()) {
                top = q.front();
                if (top->leftchild == NULL && top->rightchild == NULL) {
                    q.pop();
                } else {
                    return false;
                }
            }
            return true;
        }
    }
    return true;
}
