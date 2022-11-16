//
// Created by 朱俊杰 on 2022/11/8.
//
#include "iostream"

using namespace std;
const int MAXN = 1005;
int parent[MAXN];
int rnk[MAXN];
int n, m;

void Init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int Find(int x) {
    if (x != parent[x])
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry) return;
    if (rnk[rx] < rnk[ry])
        parent[rx] = ry;
    else {
        if (rnk[rx] == rnk[ry])
            rnk[rx]++;
        parent[ry] = rx;
    }
}


int main() {
    /**
     * scanf 函数返回成功读入的数据项数，读入数据时遇到了“文件结束”则返回EOF。
     * scanf ( "%d %d" ,&a,&b);
     * 函数返回值为 int 型。如果a和b都被成功读入，那么 scanf 的返回值就是2；
     * 如果只有a被成功读入，返回值为1；
     * 如果a和b都未被成功读入，返回值为0；
     * 如果遇到错误或遇到end of file，返回值为EOF。end of file为Ctrl+z 或者Ctrl+d。
     * 其中EOF的值为-1
     */

    while (~scanf("%d", &n)) {
        if (n == 0) break;
        scanf("%d", &m);
        Init();
        for (int i = 1; i <= m; i++)        //输入m条边
        {
            int a, b;
            scanf("%d%d", &a, &b);
            Union(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)    //求子树个数ans
            if (parent[i] == i)
                ans++;
        printf("%d\n", ans - 1);        //结果为ans-1
    }
}

