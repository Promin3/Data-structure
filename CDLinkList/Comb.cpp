//
// Created by 朱俊杰 on 2022/10/8.
//
//该方法将将两个循环双链表合并
#include "CDLinkList.cpp"

template<typename T>
void Comb(CDLinkList<T> &a, CDLinkList<T> &b) {
    DLinkNode<T> *ra = a.dhead->prior;
    DLinkNode<T> *rb = b.dhead->prior;
    ra->next = b.dhead->next;
    b.dhead->next->prior = ra;
    rb->next = a.dhead;
    a.dhead->prior = rb;
    b.dhead->next = b.dhead;
    b.dhead->prior = b.dhead;
}

//int main() {
//    int a[] = {4, 5, 6, 7};
//    int b[] = {7, 5, 0, 8, 6};
//    CDLinkList<int> j,k;
//    j.CreateListR(a,4);
//    j.display();
//    k.CreateListR(b,5);
//    k.display();
//    Comb(j,k);
//    j.display();
//    return 0;
//}

