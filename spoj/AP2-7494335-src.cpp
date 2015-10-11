#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<stack>
#include<queue>

#define ll long long
#define s(i) scanf("%lld",&i)
#define ps(i) printf("%lld ",i)
#define pa(i) printf("%lld\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)

using namespace std;
int main()
{
    ll t, x, y, d, a, n,s;
    s(t);
    while(t--)
    {
        s(x);s(y);s(s);
        n = (s * 2)/(x+y);
        d = (y-x)/(n-5);
        a = x - 2*d;
        pa(n);
        while(n--)
        {
            ps(a);
            a += d;
        }
        printf("\n");
    }
}
