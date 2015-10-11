#include<iostream>
#include<iomanip>
using namespace std;
int fee[111],fun[111];
int dp[511][111];
//int topay;
int ks(int  bg, int i)
{
    if(dp[bg][i])
      return dp[bg][i];
    if(i==0)
      return 0;
    if(bg<fee[i])
      {
          dp[bg][i-1]=ks(bg,i-1);
          return dp[bg][i-1];
      }
    dp[bg][i]=max(ks(bg,i-1),ks(bg-fee[i],i-1)+fun[i]);
    //cout<<"dp"<<bg<<","<<i<<"="<<dp[bg][i]<<endl;
    return dp[bg][i];
}
int main()
{
    int bg,pt;
    cin>>bg>>pt;
    while(1)
    {
      if(bg==0&&pt==0)
        break;
      for(int i=0; i<=bg;i++)
        for(int j=0;j<=pt;j++)
          dp[i][j]=0;
      for(int i=1;i<=pt;i++)
        cin>>fee[i]>>fun[i];
      int fun_got=ks(bg,pt);
      int to_pay=bg;
      while(ks(to_pay,pt)==ks(bg,pt))
        to_pay--;
      cout<<to_pay+1<<" "<<fun_got<<endl;
      cin>>bg>>pt;
    }
}
