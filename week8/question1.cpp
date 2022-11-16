#include <iostream>
#include "E:\ClionWorkSpace\Linklist\LinkList.cpp"

int maxlength(LinkList<char> *s) {
    int n = 0, max = 0;
    LinkNode<char> *p = s->head->next, *pre;
    while (p != nullptr) {
        n = 1;
        pre = p;
        p = p->next;
        while (p != nullptr && p->data == pre->data) {
            n++;
            p = p->next;
        }
        if(n > max) max = n;
    }
    return max;
}