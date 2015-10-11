#include<iostream>
using namespace std;
int a[1000000]={0};
unsigned int f(int n)
{
  if(n<1000000)
  {
    if(n==0)
    return 0;
    else if(a[n]==0)
    {
        a[n]+=f(n/2)+f(n/3)+f(n/4);
        if(a[n]<n)
        a[n]=n;
    }
    return a[n];
  }
  else
  {
      unsigned int sum=0;
      if((n/2+n/3+n/4)>n)
    {
       sum=f(n/2)+f(n/3)+f(n/4);
    }
    return sum;
  }      
        
}    
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<f(n)<<endl;
    }
    return 0;
}        
