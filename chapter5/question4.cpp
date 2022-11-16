////
//// Created by 朱俊杰 on 2022/11/2.
////
//#include "iostream"
//
//void Countsort(double *A, int *B, int n) {
//    int i, j, k;
//    double r0;
//    i = 1;
//    while (i < n) {
//        if (B[i] != i) {
//            j = i;
//            while (B[j] != i) {
//                k = B[j];
//                B[j] = B[k];
//                B[k] = k;
//                r0 = A[j];
//                A[j] = A[k];
//                A[k] = r0;
//            }
//            i++;
//        }
//    }
//}
//
//int main() {
//    double a[] = {1, 2, 3, 4, 5};
//    int b[] = {2, 3, 4, 1, 0};
//    Countsort(a, b, 5);
//    for (double i : a) {
//        std::cout << i << " ";
//    }
//}