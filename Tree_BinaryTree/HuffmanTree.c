//
// Created by 朱俊杰 on 2022/11/8.
//
struct HTNode {
    char data;            // 结点值
    double weight;        // 权值
    int parent;           // 父亲结点
    int leftChild;        // 左孩子结点
    int rightChild;       // 右孩子结点
};

/**
 * 给定 n0 个权值，构造一棵含有 n0 个给定权值的叶子结点的二叉树，使其 weighted path length 最小
 * @param ht 用 ht 数组存放哈夫曼树
 * @param n0 带权值叶子结点个数
 */
void CreateHuffmanTree(HTNode ht[], int n0) {
    double min1, min2;
    int lnode, rnode;

    for (int i = 0; i < 2 * n0 - 1; ++i) {
        ht[i].parent = ht[i].rightChild = ht[i].leftChild = -1;
    }
    for (int i = n0; i < 2 * n0 - 1; ++i) {
        min1 = min2 = 2147483647; // short int 最大值
        lnode = -1, rnode = -1;
        for (int k = 0; k < i; ++k)
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    min1 = ht[k].weight;
                    rnode = lnode;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].leftChild = lnode;
        ht[i].rightChild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}