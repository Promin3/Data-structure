//
// Created by kevin on 2023/2/21.
//

#include "vector"
using namespace std;

void BubbleSort(vector<int> &R, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int exchange = false;
        for (int j = n - 1; j > i; --j) {
            if(R[j] < R[j - 1]){
                swap(R[j], R[j - 1]);
                exchange = true;
            }
        }
        if( !exchange)
            return;
    }
}