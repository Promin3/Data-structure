//
// Created by 朱俊杰 on 2022/11/9.
//
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

int MinBranch(BTreeNode *p){
    int min,min1,min2;
    if(p == nullptr)
        return 0;
    else{
        min1 = MinBranch(p->leftchild);
        min2 = MinBranch(p->rightchild);
        min = min1 < min2 ? min1 + 1 : min2 + 1;
        return min;
    }
}