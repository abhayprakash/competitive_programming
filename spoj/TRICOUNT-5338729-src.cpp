#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    unsigned long long int v[1000001];
    v[0]=0;
    v[1]=1;
    unsigned long long int a2=4,a3=4;
    for(int i=2;i<1000001;i++)
    {
        v[i]=v[i-1]+a2;
        a2+=a3;
        if(i%2==0)
        a3+=2;
        else
        a3+=1;
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",v[n]);
    }
}