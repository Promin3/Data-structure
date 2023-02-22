//
// Created by kevin on 2023/2/19.
//
#include "vector"

using namespace std;

int BinSearch2(vector<int> &v, int left, int right, int k);

int _BinSearch(vector<int> &v, int k) {
    return BinSearch2(v, 0, v.size() - 1, k);
}

int BinSearch2(vector<int> &v, int left, int right, int k) {
    if (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (k == v[mid])
            return mid;
        if (k < v[mid])
            return BinSearch2(v, left, mid - 1, k);
        else
            return BinSearch2(v, mid + 1, right, k);
    } else
        return -1;
}
