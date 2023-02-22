//
// Created by kevin on 2023/2/21.
//

#include "vector"

using namespace std;

template<typename T>
class Heap {
    int n;
    vector<T> R;
public:
    Heap() : n(0) {}

    void shiftDown(int low, int high) {
        int i = low;
        int j = i * 2 - 1;
        int tmp = R[i];
        while (j <= high) {
            if (j < high && R[j] < R[j + 1])
                j++;
            if (tmp < R[j]) {
                R[i] = R[j];
                i = j;
                j = i * 2 - 1;
            } else
                break;
        }
        R[i] = tmp;
    }

    // 从叶子节点向上筛选
    void shiftUp(int j) {
        int i = (j - 1) / 2;
        while (true) {
            if (R[i] < R[j])
                swap(R[i], R[j]);
            if (i == 0) break;
            j = i;
            i = (j - 1) / 2;
        }
    }


    void push(T e) {
        n++;
        if (R.size() >= n)
            R[n - 1] = e;
        else
            R.push_back(e);
        if (n == 1)
            return;
        shiftUp(n - 1);
    }

    T pop() {
        if (n == 1) {
            n = 0;
            return R[0];
        }
        T e = R[0];
        R[0] = R[n - 1];
        n--;
        shiftDown(0, n - 1);
        return e;
    }

    T getTop() {
        return R[0];
    }

    T empty() {
        return n == 0;
    }
};