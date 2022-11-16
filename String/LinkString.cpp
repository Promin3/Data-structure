//
// Created by 朱俊杰 on 2022/10/13.
//

struct LinkNode {
    char data;
    LinkNode *next;

    LinkNode() : next(nullptr) {};

    LinkNode(char c) : data(c), next(nullptr) {};
};

class LinkString {
public:
    LinkNode *head;
    int length;

    LinkString &InsStr(int i, LinkString &t);
};

LinkString &LinkString::InsStr(int i, LinkString &t) {
    static LinkString s;
    if (i < 0 || i > length)return s;// i = 0时 ,插到头结点和首节点处,i = length时,插到尾部
    LinkNode *p = head->next, *pl = t.head->next;
    LinkNode *r = s.head, *q;
    for (int j = 0; j < i; ++j) {
        q = new LinkNode(p->data);
        r->next = q;
        r = q;
        p = p->next;
    }
    while (pl != nullptr) {
        q = new LinkNode(pl->data);
        r->next = q;
        r = q;
        pl = pl->next;
    }
    while (p != nullptr){
        q = new LinkNode(p->data);
        r->next = q;
        r = q;
        p = p->next;
    }
    s.length = this->length + t.length;
    r->next = nullptr;
    return s;

}



