#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int gcd(int m,int n)
{
           if(m%n!=0)
           gcd(n,m%n);
           else if(m%n==0)
           return n;
            }
int main()
{
    int n;
    scanf("%d",&n);
    int t[n],d[n-1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        d[i]=t[i+1]-t[i];
    }
    sort(d,d+n-1);int cd=gcd(d[0],d[1]);
    for(int j=2;j<n-1;j++)
    {
        cd=gcd(cd,d[j]);
        if(cd==1)
        break;
    }
    int cnt=(1+(t[n-1]-t[0])/cd)-n;
    printf("%d\n",cnt);
    return 0;
}
