//
// Created by kevin on 2023/2/21.
//

#include "vector"

using namespace std;

void shellSort(vector<int> &R, int n) {
    int d = n / 2;
    while (d > 0) {
        for (int i = d; i < n; ++i) {
            if (R[i] < R[i - d]) {
                int tmp = R[i];
                int j = i - d;
                do {
                    R[j + d] = R[j];
                    j -= d;
                } while (j >= 0 && R[j] > tmp);
                R[j + d]  = tmp;
            }
        }
         d = d / 2;
    }
}