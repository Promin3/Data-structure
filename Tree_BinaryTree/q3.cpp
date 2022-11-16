//
// Created by 朱俊杰 on 2022/11/9.
//
#include "E:\ClionWorkSpace\Tree_BinaryTree\BTree.cpp"

void leafFromRightToLeft(BTreeNode *p){
    if(p != nullptr){
        if(p->rightchild == nullptr && p->leftchild == nullptr){
            cout << p->data;
        }
        leafFromRightToLeft(p->rightchild);
        leafFromRightToLeft(p->leftchild);
    }
}

