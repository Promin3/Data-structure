#include <iostream>

using namespace std;

template<typename T>
struct DLinkNode {
    T data;
    DLinkNode *prior;
    DLinkNode *next;

    DLinkNode() : prior(nullptr), next(nullptr) {};

    DLinkNode(T d) : data(d), prior(nullptr), next(nullptr) {};

};

template<typename T>
class CDLinkList {
public:
    DLinkNode<T> *dhead;

    CDLinkList() {
        dhead = new DLinkNode<T>();
        dhead->next = dhead;
        dhead->prior = dhead;
    }

    ~CDLinkList() {
        DLinkNode<T> *p, *pre;
        pre = dhead;
        p = dhead->next;
        while (p != dhead) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }

    void CreateListF(T a[], int n);

    void CreateListR(T a[], int n);

    void Add(T e);

    int getLength();

    DLinkNode<T> geti(int i);

    bool Insert(int i, T e);

    bool Delete(int i);

    void display();

};

template<typename T>
void CDLinkList<T>::CreateListR(T *a, int n) {
    DLinkNode<T> *p, *r;
    r = dhead;
    for (int i = 0; i < n; ++i) {
        p = new DLinkNode<T>(a[i]);
        r->next = p;
        p->prior = r;
        r = r->next;
    }
    r->next = dhead;
    dhead->prior = r;
}

template<typename T>
void CDLinkList<T>::CreateListF(T *a, int n) {
    DLinkNode<T> *s;
    for (int i = 0; i < n; ++i) {
        s = DLinkNode<T>(a[i]);
        s->next = dhead->next;
        dhead->next->prior = s;
        dhead->next = s;
        s->prior = dhead;
    }
}

template<typename T>
void CDLinkList<T>::Add(T e) {
    DLinkNode<T> *s = new DLinkNode<T>(e);
    s->next = dhead;
    s->prior = dhead->prior;
    dhead->prior->next = s;
    dhead->prior = s;
}

template<typename T>
int CDLinkList<T>::getLength() {
    DLinkNode<T> *p = dhead;
    int cnt = 0;
    while (p->next != dhead) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

template<typename T>
DLinkNode<T> CDLinkList<T>::geti(int i) {
    if (i < -1) return nullptr;
    int j = -1;
    DLinkNode<T> *s = dhead;
    while (j < i && s->next != dhead) {
        j++;
        s = s->next;
    }
    return s;
}

template<typename T>
bool CDLinkList<T>::Insert(int i, T e) {
    if (i < 0 || i >= this->getLength()) return false;
    DLinkNode<T> *pre = geti(i - 1);
    DLinkNode<T> *s = DLinkNode<T>(e);
    s->next = pre->next;
    pre->next->prior = s;
    s->prior = pre;
    pre->next = s;
}

template<typename T>
bool CDLinkList<T>::Delete(int i) {
    if (i < 0 || i >= this->getLength()) return false;
    DLinkNode<T> *p;
    p = geti(i);
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return true;
}

template<typename T>
void CDLinkList<T>::display() {
    DLinkNode<T> *p = this->dhead->next;
    while (p != dhead){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



