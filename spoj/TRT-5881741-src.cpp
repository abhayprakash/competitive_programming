#include<iostream>
using namespace std;
int st[2000][2000]={0};
int fn(int i, int j,int n)
{
    if(i==j)
      return (n-j+i)*st[i][i];
    if(st[i][j])
      return st[i][j];
    st[i][j]=max((n-j+i)*st[i][i]+fn(i+1,j,n),(n-j+i)*st[j][j]+fn(i,j-1,n));
    return st[i][j];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>st[i][i];
    cout<<fn(0,n-1,n);
}
