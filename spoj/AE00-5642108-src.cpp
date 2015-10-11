#include<iostream>
#include<math.h>
using namespace std;
int div(int n)
{
    int c=0;
    for(int i=1;i<=sqrt(n);i++)
      if(n%i==0) c++;
      return c;
}
int fn(int n)
{
    if(n==1) return 1;
    else return fn(n-1)+div(n);
}
int main()
{
    int n;
    cin>>n;
    cout<<fn(n);
}
