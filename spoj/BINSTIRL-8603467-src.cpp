#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<((((n-m)&(m-1)/2)==0)?1:0 )<<endl;
    }
}
