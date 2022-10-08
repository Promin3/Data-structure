//
// Created by 朱俊杰 on 2022/10/7.
//
#include "DLinkList.cpp"
template<typename T>
void DeleteFirstX(DLinkList<T> &l, T x){
    DLinkNode<T> *p = l.dhead->next;
    while (p != nullptr && p->data != x){
        p = p->next;
    }
    if(p != nullptr){
        if(p->next != nullptr)
            p->next->prior = p->prior;
        p->prior->next = p->next;
        delete p;
    }
}

int main(){
    DLinkList<int> a;
    int array[] = {7,8,9,2,4};
    a.CreateListR(array,5);
    a.display();
    DeleteFirstX(a,2);
    a.display();
    return 0;
}