#include <stdio.h>
#define maxn 100005
int max_subsqu_sum(int n, int a[])
{
    int maxsum = 0, thisssum = 0;
    for (int i = 0; i < n; i++)
    {
        thisssum += a[i];
        if (thisssum > maxsum)
            maxsum = thisssum;
        else if (thisssum < 0)
            thisssum = 0;
    }
    if(maxsum < 0) return 0;
    else return maxsum;5
}

int main()
{
    int n;
    int a[maxn] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",max_subsqu_sum(n,a));
}