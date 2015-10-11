#include<iostream>
#include<stdio.h>
 
#include<cstring>
using namespace std;
int main()
{
    static int test,dp[2001][2001],n,m;
    //string s,t;
    char s[2001], t[2001];
    scanf("%d",&test);
    while(test--)
    {
        //cin>>s>>t;
        scanf("%s%s",&s,&t);
        n = strlen(s); m=strlen(t);
        //n = s.length(); m = t.length();
        memset(dp,0,sizeof(dp)/sizeof(int));
        for(int i= 1;i<=n;i++)
          dp[i][0]=i;
        for(int j= 1;j<=n;j++)
          dp[0][j]=j;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }/*
        for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
        }*/
        printf("%d\n",dp[n][m]);
    }
}