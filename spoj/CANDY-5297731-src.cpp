#include<iostream>
#include<numeric>
using namespace std;
int mod(int n)
{
    if(n<0)
    return (-n);
    return n;
}
int main()
{
    int t;
    cin>>t;
    while(t!=-1)
    {
        int a[t];
        for(int i=0;i<t;i++)
        cin>>a[i];
        int sum=accumulate(a,a+t,0);
        if(sum%t!=0)
        cout<<"-1\n";
        else
        {
            int avg=sum/t;
            int b[t];
            for(int i=0;i<t;i++)
            b[i]=mod(a[i]-avg);
            int sum_steps=accumulate(b,b+t,0);
            cout<<sum_steps/2<<endl;
        }
        cin>>t;
    }
    return 0;
}
