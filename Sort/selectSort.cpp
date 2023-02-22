//
// Created by kevin on 2023/2/21.
//
#include "vector"

using namespace std;

void SelectSort(vector<int> &R, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (R[j] < R[minj])
                minj = j;
        }

        if (minj != i)
            swap(R[i], R[minj]);
    }
}