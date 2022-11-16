//
// Created by 朱俊杰 on 2022/11/7.
//
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"
#include <vector>

BTreeNode *CreateBtree21(vector<char> posts, int i, vector<char> ins, int j, int n);






void CreateBtree2(BTree &bt, vector<char> postorderSequence, vector<char> inorderSequence) {
    int n = postorderSequence.size();
    bt.rootnode = CreateBtree21(postorderSequence, 0, inorderSequence, 0, n);
}


BTreeNode *CreateBtree21(vector<char> posts, int i, vector<char> ins, int j, int n) {
    //递归终点
    if (n <= 0)return nullptr;
    // 后序序列取最后一个值作为根结点
    char d = posts[n - i - 1];
    auto *b = new BTreeNode(d);
    // 计算子树左子树的结点个数
    int p = j;
    while (ins[p] != d) p++; // 直到中序序列对应的根结点
    int k = p - j; // 左子树的结点个数
    b->leftchild = CreateBtree21(posts, i + 1, ins, j, k);
    b->rightchild = CreateBtree21(posts, i + k, ins, p + 1, n - k - 1);
    return b;
}
