#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int func(int n)
{
    if(n==1||n==2||n==3||n==4)
     return 3;
    else
     return func(ceil((float)n/2.0))+1;
}
int main()
{
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        //cin>>m;
        scanf("%d",&m);
        //cout<<func(m)<<endl;
        printf("%d\n",func(m));
    }
}
