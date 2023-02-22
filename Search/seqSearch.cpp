#include <iostream>
#include "vector"

using namespace std;

int seqSearch1(vector<int> &v, int k) {
    int n = v.size();
    int i = 0;
    while (v[i] != k && i < n)
        i++;
    if (i >= n)
        return -1;
    else
        return i;
}

int seqSearch2(vector<int> &v, int k) {
    int n = v.size();
    v.push_back(k);
    int i = 0;
    while (v[i] != k)
        i ++;
    if(i == n)
        return -1;
    else
        return i;
}