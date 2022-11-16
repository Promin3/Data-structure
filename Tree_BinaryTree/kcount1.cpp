//
// Created by 朱俊杰 on 2022/11/6.
//
/**
* 用cnt变量计第k层结点个数（初始为0）。
* 设计队列中元素类型为QNode类，包含表示当前结点层次lev和结点地址node两个成员变量。先将根结点进队（根结点的层次为1）。在层次遍历中出队一个结点p：
* 若结点p层次大于k，返回cnt（继续层次遍历不可能再找到第k层的结点）。
* 若结点p是第k层的结点（p.lev=k），cnt增1。
* 若结点p的层次小于k，将其孩子结点进队，孩子结点的层次为双亲结点的层次加1。
* 最后返回cnt。

 */
#include <queue>
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

struct QNode {
    int lev;
    BTreeNode *node;

    QNode(int lev, BTreeNode *node) : lev(lev), node(node) {}
};

int kcount1(BTree &bt, int k) {
    int cnt = 0;
    queue<QNode> qu;
    qu.push(QNode(1, bt.rootnode));
    while (!qu.empty()) {
        QNode first = qu.front();
        qu.pop();
        if (first.lev > k)
            return cnt;
        if (first.lev == k)
            cnt++;
        else {
            if (first.node->leftchild != nullptr)
                qu.push(QNode(first.lev + 1, first.node->leftchild));
            if (first.node->rightchild != nullptr)
                qu.push(QNode(first.lev + 1, first.node->rightchild));
        }
    }
    return cnt;// 队列空了，表示二叉树已经层次遍历了一遍,返回0个
}
