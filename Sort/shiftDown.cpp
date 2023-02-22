#include "vector"

using namespace std;

void shiftDown(vector<int> &R, int low, int high)   // 左右子树均为堆，只需要调整根节点，将子树中最大的节点置为根节点
{                                                   // low is root ,high is last leaf
    int i = low;                                    // 自顶向下筛选
    int j = 2 * i + 1;                              // left child
    int tmp = R[i];
    while (j <= high) {
        if (j < high && R[j] < R[j + 1])            // lchild is biggger, shift to lchild
            j++;                                    // 切到rchild
        if (tmp < R[j])                             // 查找到比根节点大的，将根节点置为该值
        {
            R[i] = R[j];                            // 覆盖
            i = j;                                  // i 指向用于覆盖的 节点
            j = 2 * i + 1;                          // j 指向 i 节点的子节点
        } else
            break;                                  // tmp > R[j] 则二叉树是大根堆，退出循环
    }
    R[i] = tmp;                                     // i 节点置为原来的根节点
}