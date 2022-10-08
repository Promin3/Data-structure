//
// Created by 朱俊杰 on 2022/10/6.
//

#include "LinkList.cpp"

template<typename T>
void Reverse(LinkList<T> &L) {
    LinkNode<T> *p = L.head->next, *q;
    L.head->next = nullptr;
    while (p != nullptr) {
        q = p->next;// q 暂时记录p后继结点地址
        p->next = L.head->next;
        L.head->next = p;
        p  = q;
    }
}
//
//int main(){
//    LinkList<int> a;
//    a.Add(1);
//    a.Add(4);
//    a.Add(8);
//    a.Add(7);
//    a.Add(6);
//    a.display();
//
//    Reverse(a);
//    a.display();
//    return 0;
//}