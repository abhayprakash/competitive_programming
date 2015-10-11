#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int t;
    cin>>t;
    int sum=0;
    int n;
    for(int i=0;i<t;i=i+1)
    {
        cin>>n;
        if(n>0)
        sum=sum+n;
    }
    cout<<sum<<endl;
    return 0;
}
