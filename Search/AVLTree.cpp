//
// Created by kevin on 2023/2/20.
//

template<typename T1, typename T2>
struct AVLNode {
    T1 key;
    T2 data;
    int ht;
    AVLNode *lchild, *rchild;

    AVLNode(T1 key, T2 data) : key(key), data(data) {
        ht = 1;
        lchild = rchild = nullptr;
    }
};


template<typename T1, typename T2>
class AVLTree {
    AVLNode<T1, T2> *r;
public:
    AVLTree() : r(nullptr) {}

    int getht(AVLNode<T1, T2> *p) {
        return p->ht;
    }

    //基本运算算法

    // LL右旋算法
    AVLNode<T1, T2> *right_rotate(AVLNode<T1, T2> *a) {
        AVLNode<T1, T2> *b = a->lchild;
        a->lchild = b->rchild;
        b->rchild = a;
        a->ht = max(getht(a->lchild), getht(a->rchild)) + 1;
        b->ht = max(getht(b->lchild), getht(b->rchild)) + 1;
        return b;
    }

    AVLNode<T1, T2> *LL(AVLNode<T1, T2> *a) {
        return right_rotate(a);
    };

    // RR左旋算法
    AVLNode<T1, T2> *left_rotate(AVLNode<T1, T2> *a) {
        AVLNode<T1, T2> *b = a->rchild;
        a->rchild = b->lchild;
        b->lchild = a;
        a->ht = max(getht(a->lchild), getht(a->rchild)) + 1;
        b->ht = max(getht(b->lchild), getht(b->rchild)) + 1;
        return b;
    }

    AVLNode<T1, T2> *RR(AVLNode<T1, T2> *a) {
        return left_rotate(a);
    };

    AVLNode<T1, T2> *LR(AVLNode<T1, T2> *a) {
        AVLNode<T1, T2> *b = a->lchild;
        a->lchild = left_rotate(b);
        return right_rotate(a);
    }

    AVLNode<T1, T2> *RL(AVLNode<T1, T2> *a) {
        AVLNode<T1,T2> *b = a->rchild;
        a->rchild = right_rotate(b);
        return left_rotate(a);
    }

};