#include <stack>
#include "iostream"

using namespace std;

struct BTreeNode {
    char data;
    BTreeNode *leftchild;
    BTreeNode *rightchild;

    BTreeNode() : leftchild(nullptr), rightchild(nullptr) {};

    BTreeNode(char d) : data(d), leftchild(nullptr), rightchild(nullptr) {};

};


class BTree {
public:
    BTreeNode *rootnode;

    BTree() : rootnode(nullptr) {};// 初始化一个BTree，其根节点为null

    void CreateBTree(string str);//根据字符串创建二叉树

    void Display();

    BTreeNode *FindNode(char x);

    int Height();

    void DestroyBTree(BTreeNode *b);

    void preorder();

    void inorder();

    void postorder();

    ~BTree();
};


void DisplayBTree(BTreeNode *b);

BTreeNode *findnode(BTreeNode *pNode, char x);

int height(BTreeNode *);

void preorder1(BTreeNode *);

void inorder1(BTreeNode *);

void postorder1(BTreeNode *);


void BTree::CreateBTree(string str) {
    stack<BTreeNode *> st;
    BTreeNode *p;
    bool flag;
    int position = 0;
    while (position < str.length()) {
        switch (str[position]) {
            case '(':
                st.push(p);
                flag = true;
                break;
            case ')':
                st.pop();
                break;
            case ',':
                flag = false;
                break;
            default:
                p = new BTreeNode(str[position]);
                if (this->rootnode == nullptr) this->rootnode = p;//尚未创建根节点
                else {
                    if (flag && !st.empty())
                        st.top()->leftchild = p;
                    else if (!st.empty())
                        st.top()->rightchild = p;
                }
                break;
        }
        position++;
    }
}

void BTree::Display() {
    DisplayBTree(rootnode);
}

void DisplayBTree(BTreeNode *b) {
    if (b != nullptr) {
        cout << b->data;
        if (b->leftchild != nullptr || b->rightchild != nullptr) {
            cout << '(';
            DisplayBTree(b->leftchild);
            cout << ',';
            DisplayBTree(b->rightchild);
            cout << ')';
        }
    }
}


BTreeNode *BTree::FindNode(char x) {
    return findnode(rootnode, x);
}

BTreeNode *findnode(BTreeNode *pNode, char x) {
    if (pNode == nullptr) return nullptr;
    else if (pNode->data == x) return pNode;
    else {
        BTreeNode *p = findnode(pNode->leftchild, x);
        if (p != nullptr) return p;
        else
            return findnode(pNode->rightchild, x);
    }
}


int BTree::Height() {
    return height(this->rootnode);
}

int height(BTreeNode *p) {
    if (p == nullptr)
        return 0;
    else
        return max(height(p->rightchild), height(p->leftchild)) + 1;
}


void BTree::DestroyBTree(BTreeNode *b) {
    if (b != nullptr) {
        DestroyBTree(b->leftchild);
        DestroyBTree(b->rightchild);
        delete b;
    }
}

BTree::~BTree() {
    DestroyBTree(rootnode);
    rootnode = nullptr;
}

void BTree::preorder() {
    preorder1(this->rootnode);
}

void preorder1(BTreeNode *p) {
    if (p != nullptr) {
        cout << p->data;
        preorder1(p->leftchild);
        preorder1(p->rightchild);
    }
}

void BTree::inorder() {
    inorder1(this->rootnode);
}

void inorder1(BTreeNode *p) {
    if (p != nullptr) {
        inorder1(p->leftchild);
        cout << p->data;
        inorder1(p->rightchild);
    }
}

void BTree::postorder() {
    postorder1(this->rootnode);
}

void postorder1(BTreeNode *p) {
    if (p != nullptr) {
        postorder1(p->leftchild);
        postorder1(p->rightchild);
        cout << p->data;
    }
}






//int main() {
//    string str = "A(B(D(,G)),C(E,F))";
//    char x = 'e';
//    BTree bt;
//    bt.CreateBTree(str);
//    cout << "二叉树bt:";
//    bt.Display();
//    cout << endl;
//    cout << "bt的高度:" << bt.Height() << endl;
//    if (bt.FindNode(x))
//        cout << "bt中找到值为" << x << "的结点\n";
//    else
//        cout << "bt中没有找到值为" << x << "的结点\n";
//    bt.preorder();
//    cout << endl;
//    bt.inorder();
//    cout << endl;
//    bt.postorder();
//    cout << endl;
//    cout << "销毁二叉树\n";
//    return 0;
//}
