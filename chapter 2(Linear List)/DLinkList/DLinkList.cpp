//
// Created by 朱俊杰 on 2022/10/7.
//
#include <iostream>

using namespace std;

template<typename T>
struct DLinkNode {
    T data;
    DLinkNode *prior;
    DLinkNode *next;

    DLinkNode() : next(nullptr), prior(nullptr) {}

    DLinkNode(T d) : next(nullptr), prior(nullptr), data(d) {}

};

template<typename T>
class DLinkList {
public:
    DLinkNode<T> *dhead;

    DLinkList(){
        dhead = new DLinkNode<T>();
    }



    void Add(T e);

    void CreateListF(T a[], int n);

    void CreateListR(T a[], int n);

    bool Insert(int i, T e);

    bool Delete(int i);

    int getLength();

    DLinkNode<T> geti(int i);

    void display();
};

template<typename T>
void DLinkList<T>::CreateListF(T *a, int n) {
    for (int i = 0; i < n; ++i) {
        DLinkNode<T> *s = new DLinkNode<T>(a[i]);
        s->next = dhead->next;
        if (s->next != nullptr)
            s->next->prior = s;
        dhead->next = s;
        s->prior = dhead;
    }
}

template<typename T>
void DLinkList<T>::CreateListR(T *a, int n) {
    DLinkNode<T> *pre, *s;
    pre = dhead;
    for (int i = 0; i < n; ++i) {
        s = new DLinkNode<T>(a[i]);
        pre->next = s;
        s->prior = pre;
        pre = s;
    }
    s->next = nullptr;
}

template<typename T>
DLinkNode<T> DLinkList<T>::geti(int i) {
    if (i < -1) return false;
    int j = -1;
    DLinkNode<T> *p = dhead;
    while (j < i && p != nullptr) {
        p = p->next;
        j++;
    }
    return p;
}

template<typename T>
bool DLinkList<T>::Insert(int i, T e) {
    if (i < 0)return false;
    DLinkNode<T> *p = geti(i - 1);
    DLinkNode<T> *s = new DLinkNode<T>(e);
    if (p != nullptr) {
        s->next = p->next;
        s->prior = p;
        if (p->next != nullptr)
            p->next->prior = s;
        p->next = s;
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool DLinkList<T>::Delete(int i) {
    if (i < 0) return false;
    DLinkNode<T> *p = geti(i);
    if (p != nullptr) {
        p->prior->next = p->next;
        if (p->next != nullptr)
            p->next->prior = p->prior;
        delete p;
        return true;
    } else {
        return false;
    }
}

template<typename T>
void DLinkList<T>::display() {
    DLinkNode<T> *p = dhead->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template<typename T>
void DLinkList<T>::Add(T e) {
    DLinkNode<T> *p =new DLinkNode<T>(e);
    DLinkNode<T> *q = dhead;
    while (q->next != nullptr) {
        q = q->next;
    }
    q->next = p;
    p->prior = q;
}

template<typename T>
int DLinkList<T>::getLength() {
    int cnt = 0;
    DLinkNode<T> *p = dhead;
    while (p->next!= nullptr) {
        p = p->next;
        cnt++;
    }
    return cnt;
}




