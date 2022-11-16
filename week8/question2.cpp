//
// Created by 朱俊杰 on 2022/10/26.
//

#include "E:\ClionWorkSpace\String\SqString.cpp"

void move(SqString &s) {
    int i = 0, j = s.length - 1;
    while (i < j) {
        while (s.data[i] >= '0' && s.data[j] <= '9')
            i++;
        while (s.data[j] >= 'a' && s.data[j] <= 'z')
            j--;
        if (i < j) {
            char tmp = s.data[i];
            s.data[i] = s.data[j];
            s.data[j] = tmp;
        }
    }
}
