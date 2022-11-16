//
// Created by 朱俊杰 on 2022/11/3.
//

#include <iostream>
#include "algorithm"
using namespace std;

int FindMaxElement(int a[],int num){
    if(num == 1) return a[0];
    else{
        int mid = num/2;
        int b[mid];
        int c[num - mid];
        for (int i = 0; i < mid; ++i) {
            b[i] = a[i];
        }
        for (int j = 0; j < num - mid; ++j) {
            c[j] = a[j + mid];
        }
        return max(FindMaxElement(b,mid),FindMaxElement(c,num - mid));
    }
}
/**
 *
 * @return 输出最大元素 9
 */
int main(){
    int a[] = {7,8,5,9,5,2};
    cout << FindMaxElement(a,6);
    return 0;
}