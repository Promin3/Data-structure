#include <iostream>
using namespace std;
int main()
{
    unsigned int n, sum;
    while (scanf("%d", &n) != EOF)
    {
        sum = n*(n+1)/2;
        printf("%d\n\n",sum);
    }
    return 0;
}