//
// Created by kevin on 2023/2/20.
//

#include "iostream"

using namespace std;

unsigned int BKDRHHash(char *str) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return hash;
}

int main() {
    char s[] = {'a', 'b', 'c'};
    string s1 = "kevin";
    string s2 = "abc";
    // const char * p = s1.c_str(); const char *
    // non-const char *
    char *p = s1.data();
    char *q = s2.data();
    cout << BKDRHHash(s) << endl;
    cout << BKDRHHash(p) << endl;
    cout << BKDRHHash(q) << endl;
    return 0;
}