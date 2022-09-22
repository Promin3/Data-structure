//辗转相除法
//gcd(a,b) = gcd(b,a mod b)
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    int r;
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << gcd(a,gcd(b,c));
    return 0;
} 