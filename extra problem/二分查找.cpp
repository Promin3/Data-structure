#include <iostream>
#define maxn 1000010
using namespace std;
int a[maxn], m, n, q;

int find(int x)
{
    int mid, l, r;
    l = 1, r = n + 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (a[l] == q)
        return l;
    else
        return -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        cout << find(q) << " ";
    }
    return 0;
}
