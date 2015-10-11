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
        int x=a[i],y=b[i];
        if(y==x||y==x-2)
        {
            if(x%2==0&&y%2==0)
            cout<<x+y<<endl;
            else if(x%2!=0&&y%2!=0)
            cout<<x+y-1<<endl;
        }
        else
        cout<<"No Number"<<endl;
        }

return 0;
}

