
// (1)  A D 合法
// (2) 下面给出算法实现,参数为传入序列 char[]

bool is_legal(char *a) {
    int countI = 0;
    int countO = 0;
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] = 'I') countI++;
        else if (a[i] = 'O') countO++;
        if (countO > countI)return false;
        i++;
    }
    return countI == countO;
}