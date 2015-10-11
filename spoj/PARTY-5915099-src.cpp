#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int bg,pt;
    cin>>bg>>pt;
    while(1)
    {
        if(bg==0&&pt==0)
          break;
        int fee[pt+1],fun[pt+1];
        int dp[bg+1][pt+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=pt;i++)
          cin>>fee[i]>>fun[i];

        for(int i=1;i<=bg;i++)
          for(int j=1;j<=pt;j++)
            {
                if(fee[j]>i)
                  dp[i][j]=dp[i][j-1];
                else
                  dp[i][j]=max(dp[i][j-1],dp[i-fee[j]][j-1]+fun[j]);
            }
        int to_pay=0,fun_got=dp[bg][pt];
        while(dp[to_pay][pt]!=fun_got)
            to_pay++;
        cout<<to_pay<<" "<<fun_got<<endl;
        cin>>bg>>pt;
    }
}

