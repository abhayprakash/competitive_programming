#include<iostream>
#include<stdio.h>
#define MOD 10000007
using namespace std;
long long int modulo(long long int n, long long int k)
{
    if(k==0)
      return 1;
    long long int mm=modulo(n,k/2);
    if(k & 1)
      return ((((mm * mm)%MOD) * (n%MOD))%MOD);
    else return ((mm * mm)%MOD);
}
int main()
{
    long long int n,k;
    cin>>n>>k;
    while(n!=0 || k!=0)
    {
        cout<<((((2*modulo(n-1,k))%MOD+modulo(n,k))%MOD+(2*modulo(n-1,n-1))%MOD)%MOD+modulo(n,n))%MOD<<endl;
        cin>>n>>k;
    }
}
