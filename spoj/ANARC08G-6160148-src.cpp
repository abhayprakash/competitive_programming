#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define get(n) scanf("%d",&n)
int main()
{
    int n,t=1,x;
    get(n);
    while(n)
    {
        int g[n][n],out[n],in[n],in_sum=0,fi_sum=0;
        memset(out,0,4*n);
        memset(in,0,4*n);

        for(int i=0;i<n;i++)
          {
            for(int j=0;j<n;j++)
            {
                get(g[i][j]);
                in_sum+=g[i][j];
            }
          }
        for(int i=0;i<n;i++)
          {
           for(int j=0;j<n;j++)
            {
                out[i]+=g[i][j];
                in[j]+=g[i][j];
            }
          }
        for(int i=0;i<n;i++)
          {
              out[i]-=in[i];
              if(out[i]>0)
                fi_sum+=out[i];
          }
        printf("%d. %d %d\n",t,in_sum,fi_sum);
        get(n);
        t++;
    }
}
