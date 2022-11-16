//
// Created by 朱俊杰 on 2022/10/7.
//
#include "iostream"

using namespace std;

struct Child {
    int no;
    Child *next;

    Child(int d) : no(d), next(nullptr) {}
};

class Joseph {
    int n, m;
    Child *first;
public:
    Joseph(int n1, int m1) : n(n1), m(m1) {}

    void CreateList() {
        first = new Child(1);
        Child *r = first, *p;
        for (int i = 2; i <= n; ++i) {
            p = new Child(i);
            r->next = p;
            r = p;
        }
        r->next = first;
    }


    void Josephquence() {
        Child *p, *q;
        p = first;
        for (int i = 0; i < n; ++i) {
            int num = 1;
            while (num != m) {
                num++;
                p = p->next;
            }
            cout << p->no << " ";
            q = p->next;
            p->no = q->no;
            p->next = q->next;
            delete q;
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cout << "请输入约瑟夫序列的n值 : ";
    cin >> n;
    cout << "请输入约瑟夫序列的m值 : ";
    cin >> m;
    Joseph j(n, m);
    cout << "n = " << n << " m = " << m << " 的约瑟夫序列为 : ";
    j.CreateList();
    j.Josephquence();
    return 0;
}