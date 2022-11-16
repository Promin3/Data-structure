// f(x) = a0 + a1*x + ... + an-1*x^(n-1) +  an*x^n
// «ÿæ≈…ÿÀ„∑® f(x) = a0 + x(a1 + x(a2 + x(...(an-1 + x(an)))))

#include <iostream>
//#include <time.h>
#define MAXN 10
using namespace std;
//clock_t start, stop;

double function(int n, double a[], double x)
{
    double p = a[n];
    for (int i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main()
{
    double x;
    scanf("%lf", &x);
    double a[MAXN] = {1,2,3,4,5,6,7,8,9,10};
    //start = clock();
    double ans = function(MAXN,a,5);
    //stop = clock();
    //double duration = (stop - start)/CLK_TCK;
    printf("%lf",ans);
}