#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int a[t],b[t];
    for(int i=0;i<t;i++)
    cin>>a[i]>>b[i];
    for(int i=0;i<t;i++)
    {
            int prod=1;
            int m=a[i]%10;
            int n=b[i]%4;
            if(b[i]==0)
            n=0;
            else if(n==0) n=4;
            for(int i=0;i<n;i++)
            prod*=m;
            cout<<prod%10<<endl;
            }
    return 0;
}