//
// Created by 朱俊杰 on 2022/10/26.
//
#include "E:\ClionWorkSpace\Linklist\LinkList.cpp"

LinkNode<char>* FindComList(LinkList<char> &L1, LinkList<char> &L2) {
    int m = L1.Getlength();
    int n = L2.Getlength();
    LinkNode<char> *p, *q;
    // 使 p,q指向的链长相等
    for (p = L1.head; m > n; m--)
        p = p->next;
    for (q = L2.head; n > m; n--)
        q = q->next;
    while (p->next != nullptr && q->next != nullptr && p->next != q->next)
        p = p->next, q = q->next;
    return p->next;
}