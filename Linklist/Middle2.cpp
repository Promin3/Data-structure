//
// Created by 朱俊杰 on 2022/10/6.
// 快慢指针法搜索链表中间位置元素
//
#include "LinkList.cpp"

template<typename T>
T Middle2(LinkList<T> &L) {
    LinkNode<T> *slow = L.head->next;
    LinkNode<T> *fast = L.head->next;
    while (fast != nullptr && slow != nullptr){
        if(fast->next == nullptr || fast->next->next == nullptr)
            return slow->data;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

//int main(){
//    LinkList<int> a,b;
//    int k[] = {4,9,5,7};
//    int j[] = {7,4,1,8,6};
//    a.CreateListR(k,4);
//    b.CreateListR(j,5);
//    cout<<Middle2(a)<<endl;
//    cout<<Middle2(b)<<endl;
//    return 0;
//}