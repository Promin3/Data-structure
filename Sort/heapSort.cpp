//
// Created by kevin on 2023/2/21.
//
#include "shiftDown.cpp"

void heapSort(vector<int> &R, int n){
    for (int i = n / 2 - 1; i >= 0; --i)
        shiftDown(R, i, n - 1);

    for (int j = n - 1; j > 0 ; j --) {
        swap(R[0], R[j]);
        shiftDown(R,0,j-1);
    }
}