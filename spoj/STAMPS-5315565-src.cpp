#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool myfn(int i,int j)
{
    return(i>j);
}
int main()
{
    int t;int count=1;
    scanf("%d",&t);
    while(t--)
    {
        int req,nof;
        scanf("%d%d",&req,&nof);
        int resv[nof];
        for(int i=0;i<nof;i++)
        scanf("%d",&resv[i]);
        sort(resv,resv+nof,myfn);
        //reverse(resv,resv+nof);
        int reqf=0;int sum=0;
        while(sum<req&&reqf<nof)
        {
            sum+=resv[reqf++];
        }
        if(sum<req)
        printf("Scenario #%d:\nimpossible\n\n",count++);
        else
        printf("Scenario #%d:\n%d\n\n",count++,reqf);
    }
    return 0;
}
