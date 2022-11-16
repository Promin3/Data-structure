//
// Created by 朱俊杰 on 2022/11/3.
//
//#include "E:\ClionWorkSpace\Linklist\LinkList.cpp"
//
//using namespace std;
//
///**
// *
// * @tparam T 模板
// * @param l 传入的链表指向的首结点
// * @param data 比较的值
// */
//template<typename T>
//void delx(LinkNode<T> *l, T data) {
//    if (l->next == nullptr)return;
//    if (l->next->data == data) {
//        LinkNode<T> *p = l->next;
//        l->next = l->next->next;
//        delete p;
//        return;
//    } else {
//        delx(l->next, data);
//    }
//}
//
///**
// *
// * @return 创建 7 8 6 5 7 ，删除 6，输出 7 8  5  7
// */
//int main() {
//    LinkList<int> list;
//    int a[] = {7, 8, 6, 5, 7};
//    list.CreateListR(a, 5);
//    list.display();
//    delx(list.head, 6);
//    list.display();
//    return 0;
//}