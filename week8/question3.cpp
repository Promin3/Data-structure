//
// Created by 朱俊杰 on 2022/10/26.
//
#include "E:\ClionWorkSpace\String\SqString.cpp"

bool Palindrome(SqString &s) {
    int i = 0, j = s.length - 1;
    while (i <= j) {
        if (s.data[i] == s.data[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}
