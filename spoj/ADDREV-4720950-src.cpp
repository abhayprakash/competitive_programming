#include<iostream>
using namespace std;
unsigned int rev(unsigned int n)
{
 int d[10000],i=0,p=1,m=0;
 while(n>0)
 {
           d[i]=n%10;
           n=n/10;
           i++;}
 for(int j=0;j<i;j++)
 {
         m=m+(p*d[i-j-1]);
         p=p*10;
         }
 return m;
} 
int main()
{
    //cout<<rev(1234)<<","<<rev(122344);
    int t;
    cin>>t;
    int a[t],b[t],c[t];
    for(int i=0;i<t;i++)
    {
            cin>>a[i]>>b[i];
            }
    for(int i=0;i<t;i++)
    {
            c[i]=rev(a[i])+rev(b[i]);
            cout<<rev(c[i])<<endl;
            }
    return 0;
}
