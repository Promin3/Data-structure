//
// Created by 朱俊杰 on 2022/10/26.
//


#include <iostream>

using namespace std;

void GetNextval(string t, int *nextval)    //由模式串t求出nextval值
{
    int j = 0, k = -1;
    nextval[0] = -1;
    while (j < t.length()) {
        if (k == -1 || t[j] == t[k])        //k为-1或比较的字符相等时
        {
            j++;
            k++;
            if (t[j] != t[k])            //两个字符不相等时
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        } else k = nextval[k];            //k回退
    }
}

int KMPval(string s, string t)            //改进的KMP算法
{
    int n = s.length(), m = t.length();
    int *nextval = new int[m];
    GetNextval(t, nextval);            //求出nextval数组
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || s[i] == t[j]) {
            i++;                    //i,j各增1
            j++;
        } else j = nextval[j];            //i不变,j回退
    }
    if (j >= m) return i - m;
    else return -1;
}

// 题目要求设计的算法
int function(string s, string t) {
    int site = KMPval(s, t), presite;
    if (site != -1) {
        while (site) {
            presite = site;
            string s2 = s.substr(site + 1, s.length() - site - 1);
            site = KMPval(s2, t);
        }
        return presite;
    }
    return -1;
}