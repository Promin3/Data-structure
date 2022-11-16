#include <iostream>

using namespace std;

template<typename T>
struct LinkNode {
    T data;
    LinkNode<T> *next;

    LinkNode() : next(nullptr) {}

    LinkNode(T d) : data(d), next(nullptr) {}
};

template<typename T>
class LinkList {
public:
    LinkNode<T> *head;

    LinkList() {
        head = new LinkNode<T>();
    }

    ~LinkList() {
        LinkNode<T> *p, *pre;
        pre = head;
        p = pre->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = p->next;
        }// pre指向最后一个结点，p指向null时结束
        delete pre;
    }

    void CreateListF(T a[], int n);

    void CreateListR(T a[], int n);

    LinkNode<T> *geti(int i);

    void Add(T e);

    int Getlength();

    bool GetElem(int i, T &e);

    bool insert(int i, T e);

    bool Delete(int i);

    void display();


    // Ctrl + B 转到定义或者声明

};

template<typename T>
void LinkList<T>::CreateListF(T *a, int n) {
    for (int i = 0; i < n; ++i) {
        LinkNode<T> *p = new LinkNode<T>(a[i]);
        p->next = head->next;
        head->next = p;
    }
}

template<typename T>
void LinkList<T>::CreateListR(T a[], int n) {
    LinkNode<T> *d, *r;
    r = head;
    for (int i = 0; i < n; ++i) {
        d = new LinkNode<T>(a[i]);
        r->next = d;
        r = d;
    }
}

template<typename T>
LinkNode<T> *LinkList<T>::geti(int i) {
    if (i < -1) return nullptr;
    int j = -1;
    LinkNode<T> *p = head;
    while (j < i && p != nullptr) {
        p = p->next;
        j++;
    }
    return p;
}

template<typename T>
void LinkList<T>::Add(T e) {
    LinkNode<T> *d = new LinkNode<T>(e);
    LinkNode<T> *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = d;
}

template<typename T>
int LinkList<T>::Getlength() {
    int num = 0;
    LinkNode<T> *p = head->next;
    while (p != nullptr) {
        p = p->next;
        num++;
    }
    return num;
}

template<typename T>
bool LinkList<T>::GetElem(int i, T &e) {
    if (i < 0)return false;
    LinkNode<T> *p = geti(i);
    if (p != nullptr) {
        e = p->data;
        return true;
    } else
        return false;
}

template<typename T>
bool LinkList<T>::insert(int i, T e) {
    if (i < 0) return false;
    LinkNode<T> *p = geti(i - 1);
    if (p != nullptr) {
        LinkNode<T> *d = LinkNode<T>(e);
        d->next = p->next;
        p->next = d;
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool LinkList<T>::Delete(int i) {
    if (i < 0)return false;
    LinkNode<T> *p = geti(i - 1);
    if (p != nullptr) {
        LinkNode<T> *q = p->next;
        if (q != nullptr) {
            p->next = q->next;
            delete q;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template<typename T>
void LinkList<T>::display() {
    LinkNode<T> *p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

