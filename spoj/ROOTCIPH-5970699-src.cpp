#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,c;
        //cin>>a>>b>>c;
        //a=-a;
        //c=-c;
        scanf("%lld%lld%lld",&a,&b,&c);
        cout<<a*a-2*b<<endl;
    }
}
