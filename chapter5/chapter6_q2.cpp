//
// Created by 朱俊杰 on 2022/11/3.
//
//#include "iostream"
//
//using namespace std;
//
//int find(string st, char c) {
//    if (st == "") return -1;
//    else if (st[st.length() - 1] == c) return st.length() - 1;
//    else return find(st.substr(0, st.length() - 1), c);
//}
///**
// * 输出3，程序正确
// * @return
// */
//int main() {
//    string st = "promin";
//    cout << find(st, 'm');
//    return 0;
//}