#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,res=0,val;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&val);
			res+=val/i;
		}
		if(res%2==0)
		  printf("BOB\n");
		else
		  printf("ALICE\n");
	}
	return 0;
}

