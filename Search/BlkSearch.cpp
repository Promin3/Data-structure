//
// Created by kevin on 2023/2/19.
//
#include "vector"

using namespace std;
struct IdxType {
    int key;
    int link;
};

void CreateI(vector<int> &R, IdxType I[], int b) { // 构建索引块[0 .. b - 1]
    int n = R.size();
    int s = (n + b - 1) / b;
    int j = 0;
    int jmax = R[j];
    for (int i = 0; i < b; ++i) {
        I[i].link = j;
        while (j <= (i + 1) * s - 1 && j <= n - 1) {
            if (R[j] > jmax)jmax = R[j];
            j++;
        }
        I[i].key = jmax;
        if (j <= n - 1)
            jmax = R[j];
    }
}

int BlkSearch(vector<int> &R, IdxType I[], int b, int k) {
    int n = R.size();
    int low = 0;
    int high = b - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (k <= I[mid].key)
            high = mid - 1;
        else low = mid + 1;
    }
    if (high + 1 >= b) return -1;
    int i = I[high + 1].link;
    int s = (n + b - 1) / n;
    if (i == b - 1)
        s = n - s * (b - 1);
    while (i <= I[high + 1].link + s - 1 && R[i] != k){
        i ++;
    }

    if(i <= I[high + 1].link + s - 1)
        return i;
    else
        return -1;
}