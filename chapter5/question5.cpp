////
//// Created by 朱俊杰 on 2022/11/2.
////
//#include "iostream"
//
//bool Sum(int a[][3], int n, int m, int &k) {
//    if (n != m) return false;
//    int sum = 0;
//    for (int i = 0; i < n; ++i)
//        sum += a[i][i] + a[i][n - 1 - i];
//    k = sum;
//    return true;
//}
//
//int main() {
//    int a[][3] = {{1, 2, 3},
//                 {4, 5, 6},
//                 {7, 8, 9}};
//    int sum;
//    if(Sum(a,3,3,sum)){
//        std::cout << sum;
//    } else{
//        std::cout << "false";
//    }
//    return 0;
//}