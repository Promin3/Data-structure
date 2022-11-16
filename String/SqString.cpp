#include <iostream>
#include <algorithm>

using namespace std;

const int MaxSize = 100;

class SqString {
public:
    char *data;
    int length;

    SqString &SubString(int i, int j);

    int Strcmp(SqString &s, SqString &t);

    int getLength();

    void CreateSqString(char *c);


};


SqString &SqString::SubString(int i, int j) {
    static SqString s;
    if (i < 0 || i >= length || j < 0 || i + j > length)
        return s;
    for (int k = i; k <= i + j - 1; k++)
        s.data[k - i] = data[k];
    s.length = j;
    return s;
}

int SqString::Strcmp(SqString &s, SqString &t) {
    int minl = min(s.getLength(), t.getLength());
    for (int i = 0; i < minl; ++i) {
        if (s.data[i] > t.data[i])
            return 1;
        else if (s.data[i] < t.data[i])
            return -1;
    }
    if (s.length = t.length)return 0;
    else if (s.length > t.length) return 1;
    else return -1;
}

int SqString::getLength() {
    return length;
}


