//
// Created by 朱俊杰 on 2022/11/7.
//
#include <vector>
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

//先函数声明
BTreeNode *CreateBTree11(vector<char>, int, vector<char>, int, int);





/**
 * construct binary tree according to preorder sequence and inorder sequence
 * @param bt 要构造的二叉树
 * @param preorderSequence 前序序列
 * @param inorderSequence  中序序列
 */
void CreateBTree1(BTree &bt, vector<char> preorderSequence, vector<char> inorderSequence) {
    int n = preorderSequence.size();
    bt.rootnode = CreateBTree11(preorderSequence, 0, inorderSequence, 0, n);
}


/**
 *
 * @param pres 先序序列和子树中序序列
 * @param i 先序序列和子先序序列首位，对应于根结点和递归调用的子树根节点
 * @param ins 中序序列和子树中序序列
 * @param j 中序序列和子中序序列首位，p = j,p自增后得到子树的左子树个数
 * @param n 子树结点个数，左子树个数为 k = p - j,右子树则为 n - k - 1
 * @return 返回产生的结点
 */
BTreeNode *CreateBTree11(vector<char> pres, int i, vector<char> ins, int j, int n) {
    if (n < 0)return nullptr;
    char d = pres[i];
    auto *b = new BTreeNode(d);
    int p = j;
    while (ins[p] != d) p++;
    int k = p - j;
    b->leftchild = CreateBTree11(pres, i + 1, ins, j, k);
    b->rightchild = CreateBTree11(pres, i + k + 1, ins, p + 1, n - k - 1);
    return b;
}


