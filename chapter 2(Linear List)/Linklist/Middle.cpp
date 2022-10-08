//
// Created by 朱俊杰 on 2022/10/6.
//
#include "LinkList.cpp"

template<typename T>
T Middle1(LinkList<T> &L) {
    int j = 0;
    int n =L.Getlength();
    LinkNode<T> *p = L.head->next;
    while (j < (n-1) / 2){
        j ++;
        p = p->next;
    }
    return p->data;
}

int main(){
    LinkList<int> a ;
    int b[] = {1,2,8,4};
    a.CreateListR(b,4);
    a.display();
    a.Add(7);
    a.display();
    cout << Middle1(a);
    return 0;
}