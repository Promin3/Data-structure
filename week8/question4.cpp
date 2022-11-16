//
// Created by 朱俊杰 on 2022/10/26.
//

#include "E:\ClionWorkSpace\String\SqString.cpp"

void StrPrint(SqString);

void SubString(SqString, SqString *, int, int);

void MaxEqSubStr(SqString S, SqString *T) {
    int i = 0, start1 = 0, start2 = 0, length1 = 1, length2 = 1;
    while (i < S.length) {
        i++;
        if (S.data[i] == S.data[start2])
        {
            length2++;
        }
        else
        {
            if (length2 > length1)
            {
                start1 = start2;
                length1 = length2;
            }
            start2 = i;
            length2 = 1;
        }
    }

    if (length1 < 2) {
        cout << "无等值子串！" << endl;

    } else {
        SubString(S, T, start1, length1);
        StrPrint(*T);
    }
}

void SubString(SqString S, SqString *T, int s, int length) {
    int j = 0, i;
    for (i = s; i < s + length; i++) {
        T->data[j++] = S.data[i];
    }

    T->length = length;
}

void StrPrint(SqString S) {
    int i;
    for (i = 0; i < S.length; i++) {
        cout << S.data[i];
    }
    cout << endl;
}
