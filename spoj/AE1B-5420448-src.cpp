#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool myfn(int i,int j)
{
    return i>j;
}
int main()
{
    int n,k,s;
    scanf("%d%d%d",&n,&k,&s);
    int b[n];
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
    int toach=k*s;
    sort(b,b+n,myfn);
    int ach=0,j=0;
    while(ach<toach)
    {
        ach+=b[j];
        j++;
    }
    printf("%d\n",j);
}

