#include<iostream>
using namespace std;
int a[841];
int main()
{
    for(int i=0;i<301;i++)
      a[i]=1;
    for(int j=1;j<20;j++)
      for(int i=1;i<20;i++)
        a[i+j+2*i*j]=0;

    for(int k=1;k<841;k++)
      if(a[k])
        cout<<2*k+1<<" ";
}
