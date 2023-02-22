//
// Created by kevin on 2023/2/16.
//

#include "vector"

using namespace std;


void BinInsertSort(vector<int> &v, int n) {
    for (int i = 1; i < n; ++i) {
        if (v[i] < v[i - 1]) {
            int temp = v[i];

            int low = 0;
            int high = i - 1;

            while (low <= high) {
                int mid = low + high >> 1;
                if (temp < v[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= high + 1; --j)
                v[j + 1] = v[j];

            v[high + 1] = temp;

        }
    }
}