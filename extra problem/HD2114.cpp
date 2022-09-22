#include <iostream>
using namespace std;
int main()
{
    int n, ans;
    while (scanf("%d", &n) != EOF)
    {
        n %= 10000;
        ans = (n * (n + 1) / 2) % 10000;
        ans = (ans * ans) % 10000;
        printf("%04d\n", ans);
    }
    return 0;
}