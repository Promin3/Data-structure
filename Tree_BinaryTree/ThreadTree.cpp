//
// Created by 朱俊杰 on 2022/11/7.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;

struct BthNode {
    char data;
    int leftTag, rightTag;
    BthNode *leftChild;
    BthNode *rightChild;

    BthNode() {};

    BthNode(char data) : data(data), leftTag(0), rightTag(0), leftChild(nullptr), rightChild(nullptr) {};
};

class ThreadTree {
    BthNode *rootnode;
    BthNode *head;
    BthNode *pre;

    void CreateBtree(string s);

    void CreateThread();

    void ThreadInorder();

    void Thread(BthNode *&p);
};

void ThreadTree::CreateBtree(string s) {
    stack<BthNode *> st;
    BthNode *p;
    bool flag;
    int position;
    while (position < s.length()) {
        switch (s[position]) {
            case '(':
                st.push(p);
                flag = true;
                break;
            case ',':
                flag = false;
                break;
            case ')':
                st.pop();
                break;
            default:
                p = new BthNode(s[position]);
                if (rootnode == nullptr)
                    rootnode = p;
                else {
                    if (flag && !st.empty())
                        st.top()->leftChild = p;
                    else if (!st.empty())
                        st.top()->rightChild = p;
                }
        }
    }
}


void ThreadTree::CreateThread() {
    head = new BthNode();
    head->leftTag = 0;
    head->rightTag = 1;
    head->leftChild = rootnode;
    if (rootnode == nullptr) {
        head->leftChild = head;
        head->rightChild = nullptr;
    } else {
        head->leftChild = rootnode;
        pre = head;
        Thread(rootnode);
        pre->rightTag = 1;
        pre->rightChild = head;
        head->rightChild = pre;
    }
}

void ThreadTree::Thread(BthNode *&p) {
    if (p != nullptr) {
        Thread(p->leftChild);
        // 前驱线索化
        if (p->leftChild == nullptr) {
            p->leftTag = 1;
            p->leftChild = pre;
        } else{
            p->leftTag = 0;
        }
        // 后继线索化
        if(pre->rightChild == nullptr){
            pre->rightTag = 1;
            pre->rightChild = p;
        } else{
            pre->rightTag = 0;
        }
        pre = p;
        Thread(p->rightChild);
    }
}

void ThreadTree::ThreadInorder() {
    BthNode * p = head->leftChild;
    while (p != head){
        while (p!=head && p->leftTag == 0)p = p->leftChild;
        cout << p->data;
        while ( p->rightTag == 1 && p->rightChild != head){
            p = p->rightChild;
            cout << p->data;
        }
        p = p->rightChild;
    }
}
