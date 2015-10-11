#include<stdio.h>
#include<stdint.h>

long long MOD = 24*1000000007LL;

int main()
{
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        unsigned long long sum=0ll;
        sum=(((n*(n-1))%MOD * (n-2))%MOD * (n-3))%MOD;
        sum /= 24;
        printf("%lld\n",sum);
    }



}
