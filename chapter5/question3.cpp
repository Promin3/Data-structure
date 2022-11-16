////
//// Created by 朱俊杰 on 2022/11/1.
////
//#include "iostream"
//
//void swap(int &x, int &y) {
//    int temp = x;
//    x = y;
//    y = temp;
//}
//
//bool reverse_matrix(int a[][3], int n, int m) {
//    if (n != m)return false;
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            swap(a[i][j], a[j][i]);
//        }
//    }
//    return true;
//}
//
//int main() {
//    int a[3][3] = {{1, 2, 3},
//                   {4, 5, 6},
//                   {7, 8, 9}};
//    reverse_matrix(a, 3, 3);
//    for (auto &i : a) {
//        for (int j : i) {
//            std::cout << j << " ";
//        }
//        std::cout << std::endl;
//    }
//
//}