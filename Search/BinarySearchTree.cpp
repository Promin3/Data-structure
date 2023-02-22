//
// Created by kevin on 2023/2/19.


#include "vector"

using namespace std;

template<typename T1, typename T2>
class BSTNode {
    T1 key;         //关键字
    T2 data;        //数据项
    BSTNode *lchild;
    BSTNode *rchild;

    BSTNode(T1 k, T2 d) {
        key = k;
        data = d;
        lchild = rchild = nullptr;
    }
};

template<typename T1, typename T2>
class BSTClass {
public:
    BSTNode<T1, T2> *r;  //根结点
    BSTNode<T1, T2> *f;  //用于临时存放待删除节点的双亲节点
    BSTClass() {
        r = f = nullptr;
    }

    ~BSTClass() {
        DestroyBTree(r);
        r = nullptr;
    }

    void DestroyBTree(BSTNode<T1, T2> *b) {
        if (b != nullptr) {
            DestroyBTree(b->lchild);
            DestroyBTree(b->rchild);
            delete b;
        }
    }

    // 基本运算
    void InsertBST(T1 k, T2 d) {
        r = _InsertBST(r, k, d);
    }

    BSTNode<T1, T2> *_InsertBST(BSTNode<T1, T2> *p, T1 key, T2 data) {
        if (p == nullptr)
            p = new BSTNode<T1, T2>(key, data);
        else if (key > p->key)
            p->rchild = _InsertBST(p->rchild, key, data);
        else if (key < p->key)
            p->lchild = _InsertBST(p->lchild, key, data);
        else
            p->data = data;
        return p;
    }

    void CreateBST(vector<T1> &k, vector<T2> &d) {
        r = new BSTNode<T1, T2>(k[0], d[0]);
        for (int i = 0; i < k.size(); ++i)
            InsertBST(k[i], d[i]);
    }

    BSTNode<T1, T2> *SearchBST(T1 k) {
        return _SearchBST(r, k);
    }

    BSTNode<T1, T2> *_SearchBST(BSTNode<T1, T2> *p, T1 k) {
        if (p == nullptr)
            return nullptr;
        if (p->key == k)
            return p;
        if (k < p->key)
            return _SearchBST(p->lchild, k);
        else
            return _SearchBST(p->rchild, k);
    }

    bool DeleteBST(T1 k) {
        f = nullptr;
        return _DeleteBST(r, k, -1);
    }

    bool _DeleteBST(BSTNode<T1, T2> *p, T1 k, int flag) {
        if (p == nullptr)
            return false;
        if (p->key == k) {
            return DeleteNode(p, f, flag);
        }
        if (k < p->key) {
            f = p;
            return _DeleteBST(p->lchild, k, 0);
        } else {
            f = p;
            return _DeleteBST(p->rchild, k, 1);
        }
    }

    bool DeleteNode(BSTNode<T1, T2> *p, BSTNode<T1, T2> *f, int flag) {
        if (p->rchild == nullptr) {
            if (flag == -1) // 双亲节点为空
                r = p->lchild;
            else if (flag == 0)
                f->lchild = p->lchild;
            else
                f->rchild = p->lchild;
        } else if (p->lchild == nullptr) {
            if (flag == -1)
                r = p->rchild;
            else if (flag == 0)
                f->lchild = p->lchild;
            else
                f->rchild = p->lchild;
        } else {    // p has lchild and rchild
            BSTNode<T1, T2> *q = p->lchild;
            BSTNode<T1, T2> *f1 = p;
            if (p->rchild == nullptr) {
                p->key = q->key;
                p->data = q->data;
                p->lchild = q->lchild;
            } else {
                while (q->rchild != nullptr) {
                    f1 = q;
                    q = q->rchild;
                }
                p->key = q->key;
                p->data = q->data;
                f1->rchild = q->lchild;
            }
        }
        return true;
    }
};


