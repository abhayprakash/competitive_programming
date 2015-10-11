#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    int noc;
    scanf("%d",&noc);
    while(noc!=0)
    {
        string s;
        cin>>s;
        int l=s.length();int cnt=0;
        int nor=l/noc;
        //cout<<nor<<"*\n";
        char row[nor][noc];
        for(int i=0;i<nor;i++)
        for(int j=0;j<noc;j++)
        {
            if(i%2==0)
            row[i][j]=s[cnt++];
            else
            row[i][noc-j-1]=s[cnt++];
        }
        for(int i=0;i<noc;i++)
        for(int j=0;j<nor;j++)
        {
            printf("%c",row[j][i]);
        }
        printf("\n");
        scanf("%d",&noc);
    }
    return 0;
}
