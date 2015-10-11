#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        int a[n],inverse[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            inverse[a[i-1]-1]=i;
        }
        for(int i=0;i<n;i++)
        {
            
            if(a[i]!=inverse[i])
            {cout<<"not ambiguous"<<endl;
             goto tag;}
        }
        cout<<"ambiguous"<<endl;
        tag:
            cin>>n;
    }

return 0;
}