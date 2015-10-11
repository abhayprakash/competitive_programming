#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,d;
    scanf("%d%d",&a,&d);
    while(a!=0||d!=0)
    {
        int b[a],c[d];
        for(int i=0;i<a;i++)
          scanf("%d",&b[i]);
        for(int j=0;j<d;j++)
          scanf("%d",&c[j]);
        sort(b,b+a);
        sort(c,c+d);
        if(b[0]<c[1])
          printf("Y\n");
        else
          printf("N\n");
        scanf("%d%d",&a,&d);
    }
}

