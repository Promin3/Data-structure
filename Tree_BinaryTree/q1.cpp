//
// Created by 朱俊杰 on 2022/11/9.
//
int log2(int x) {
    int i = 0;
    while (x != 1) {
        i++;
        x = x / 2;
    }
    return i;
}

/**
 *
 * @param i 结点编号，其中根结点编号为1
 * @return 层次
 */
int level(int i) {
    if (i == 1) return 1;
    else return log2(i) + 1;
}