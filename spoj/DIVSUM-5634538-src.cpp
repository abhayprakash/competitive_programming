#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0;
        //cin>>n;
        scanf("%d",&n);
        int a=sqrt(n);
        for(int i=2;i<=a;i++)
          {
              if(n%i==0)
                sum+=i+n/i;
          }
        if(a*a==n)
          sum-=a;
        printf("%d\n",sum+1);
    }
}
