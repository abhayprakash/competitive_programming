#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    while(n!=0||d!=0)
    {
	int a[1000001]={0};
	for(int i=2;i<=n;i++)
          a[i]=(a[i-1]+d)%i;
	printf("%d %d %d\n",n,d,a[n]+1);
        scanf("%d%d",&n,&d);
    }
}
