#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    double n;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%lf",&n);
    printf("%.8lf\n",((n-1)*(1/n) + (1/n)*(1/(n+1))));
    }
}
