#include "iostream"

using namespace std;

struct PolyNode {
    double coefficient;//系数
    int exponent;//幂指数
    PolyNode *next;

    PolyNode() : next(nullptr), coefficient(0), exponent(0) {}

    PolyNode(double c, int e) : coefficient(c), exponent(e), next(nullptr) {}

};

class PolyList {
public:
    PolyNode *head;

    PolyList() {
        head = new PolyNode();
    }

    ~PolyList() {
        PolyNode *pre = head, *p = head->next;
        while (p != NULL) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }

    void CreateList(char *filename);

    void Sort();

    void DisplayPolynome();
};

void PolyList::CreateList(char *filename) {
    freopen(filename, "r", stdin);
    PolyNode *s, *r;
    double coefficient;
    int n, exponent;
    scanf("%d", &n);
    r = head;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %d", &coefficient, &exponent);
        s = new PolyNode(coefficient, exponent);
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}

void PolyList::Sort() {
    PolyNode *p, *pre, *q;
    q = head->next;
    if (q == nullptr) return;
    p = head->next->next;
    if (p == nullptr) return;
    q->next = nullptr;
//    q = p->next;
    while (p != nullptr) {
        q = p->next;//用于保存p的下一节点，p结点用于插入有序字多项式
        pre = head;
        while (pre->next->exponent > p->exponent && pre->next != nullptr) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void PolyList::DisplayPolynome() {
    PolyNode *p = head->next;
    bool first = true;
    while (p != nullptr) {
        if (first) {
            printf("[%lf,%d]", p->coefficient, p->exponent);
            first = false;
        } else {
            printf(",[%lf,%d]", p->coefficient, p->exponent);
        }
        p = p->next;
    }
    printf("\n");
}


