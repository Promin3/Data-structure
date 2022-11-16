#include <iostream>

template<typename T>
struct LinkNode {
    T data;
    LinkNode<T> *next;

    LinkNode() : next(nullptr) {};

    LinkNode(T e) : next(nullptr), data(e) {};
};

template<typename T>
class CLinkList{
public:
    LinkNode<T> *head;
    CLinkList(){
        head = new LinkNode<T>;
        head->next = head;
    }
    ~CLinkList() {
        LinkNode<T> *pre, *p;
        pre = head, p = head->next;
        while (p != head) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
};