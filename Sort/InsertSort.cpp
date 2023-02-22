//
// Created by kevin on 2023/2/16.
//
#include "vector"

using namespace std;

void InsertSort(vector<int> &R, int n) {
    for (int i = 1; i < n; ++i) {
        if (R[i] < R[i - 1]) {
            int temp = R[i]; // 取出无序区的第一个数，并且将前面的数往后移动需要覆盖该数
            int j = i - 1;
            do {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && temp < R[j]);
            R[j + 1] = temp;
        }
    }
}

bool cmp(int x, int y) {
    if (x < y)
        return true;// 递增排序
    else
        return false;
}

void InsertSort2(vector<int> &R, int n) {
    for (int i = 1; i < n; ++i) {
        if(cmp(R[i],R[i-1])){
            int temp = R[i];
            int j = i - 1;
            while (j >= 0 && cmp(temp,R[j])){
                R[j + 1] = R[j];
                j --;
            }
            R[j + 1]  = temp;
        }
    }
}