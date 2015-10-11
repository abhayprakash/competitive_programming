#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,d;
		scanf("%d%d%d",&n,&a,&d);
		cout<<n*(2*a+(n-1)*d)/2<<endl;
	}
return 0;
}
