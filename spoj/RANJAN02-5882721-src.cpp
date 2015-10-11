#include<iostream>
using namespace std;
long long int fn(int n)
{
    if(n==1)
      return 2;
    return (3*fn(n-1)+2);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fn(n)<<endl;
    }
}
