//
// Created by 朱俊杰 on 2022/10/7.
//
#include "LinkList.cpp"

template<typename T>
void Commnodes(LinkList<T> &a, LinkList<T> &b, LinkList<T> &c) {
    LinkNode<T> *p = a.head->next;
    LinkNode<T> *q = b.head->next;
    LinkNode<T> *r = c.head;
    while (p != nullptr && q != nullptr) {
        if (p->data > q->data) {
            q = q->next;
        } else if (q->data > p->data) {
            p = p->next;
        } else {
            LinkNode<T> *s = new LinkNode<T>(p->data);
            r->next = s;
            //r = r->next;
            r = s;
            p = p->next;
            q = q->next;
        }

    }
    r->next = nullptr;
}

//int main() {
//    LinkList<int> a;
//    LinkList<int> b;
//    LinkList<int> c;
//    int a1[] = {1, 2, 3, 4, 6, 8};
//    int a2[] = {2, 4, 6, 9};
//    a.CreateListR(a1, 6);
//    b.CreateListR(a2, 4);
//    Commnodes(a, b, c);
//    c.display();
//    return 0;
//}