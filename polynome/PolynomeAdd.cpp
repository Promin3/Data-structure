//
// Created by 朱俊杰 on 2022/10/9.
//
#include "Polynome.cpp"

void PolynomeAdd(PolyList &a, PolyList &b, PolyList &c) {
    PolyNode *ap = a.head->next;
    PolyNode *bp = b.head->next;
    PolyNode *pre = c.head;
    double coef;
    while (ap != nullptr && bp != nullptr) {
        if (ap->exponent > bp->exponent) {
            PolyNode *s = new PolyNode(ap->coefficient, ap->exponent);
            pre->next = s;
            pre = pre->next;
            ap = ap->next;
        } else if (bp->exponent > ap->exponent) {
            PolyNode *s = new PolyNode(bp->coefficient, bp->exponent);
            pre->next = s;
            pre = pre->next;
            bp = bp->next;
        } else {
            coef = bp->coefficient + ap->coefficient;//指数相同时，若系数为相反数则不用添加到c多项式尾
            if (coef != 0) {
                PolyNode *s = new PolyNode(coef, ap->exponent);
                pre->next = s;
                pre = s;
            }
            ap = ap->next;
            bp = bp->next;
        }
    }

    if (bp != nullptr) {
        ap = bp;
    }

    while (ap != nullptr) {
        PolyNode *s = new PolyNode(ap->coefficient, ap->exponent);
        pre->next = s;
        pre = s;
        ap = ap->next;
    }
    pre->next = nullptr;
}


int main() {
    freopen("PolynomeAdd.out", "w", stdout);
    PolyList a, b, c;

    a.CreateList("Polynome_a.in");
    cout << "The first Polynome : ";
    a.DisplayPolynome();
    a.Sort();
    cout << "After sort : ";
    a.DisplayPolynome();

    b.CreateList("Polynome_b.in");
    cout << "The second Polynome : ";
    b.DisplayPolynome();
    b.Sort();
    cout << "After sort : ";
    b.DisplayPolynome();

    PolynomeAdd(a, b, c);
    cout << "first polynome + second polynome = ";
    c.DisplayPolynome();
    return 0;
}