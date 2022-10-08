//
// Created by 朱俊杰 on 2022/10/8.
//
#include "CDLinkList.cpp"

template<typename T>
bool Symm(CDLinkList<T> &a) {
    bool flag = true;
    DLinkNode<T> *p = a.dhead->next;
    DLinkNode<T> *q = a.dhead->prior;
    while (flag) {
        if (p->data != q->data) {
            return false;
        } else {
            if (p == q || p->next == q)
                break;
            p = p->next;
            q = q->prior;
        }
    }
    return flag;
}
//
//int main(){
//    CDLinkList<int> l;
//    l.Add(2);
//    l.Add(4);
//    l.Add(6);
//    l.Add(6);
//    l.Add(4);
//    l.Add(2);
//    l.display();
//    cout << Symm(l);
//    return 0;
//}