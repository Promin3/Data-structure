//
// Created by kevin on 2023/2/19.
//
#include "vector"

using namespace std;

int BinSearch(vector<int> &v, int k) {
    int n = v.size();
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (v[mid] == k)
            return mid;
        if (v[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}