//
// Created by 朱俊杰 on 2022/11/9.
//

#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

bool Symm(BTreeNode *p1,BTreeNode *p2){
    if(p1 == nullptr && p2 == nullptr)
        return true;
    else if(p1 == nullptr || p2 == nullptr)
        return false;
    else
        return Symm(p1->rightchild,p1->leftchild) && Symm(p2->leftchild,p2->rightchild);
}

bool Symmetric(BTreeNode *p){
    if(p == nullptr)
        return true;
    else
        return Symm(p->leftchild,p->rightchild);
}