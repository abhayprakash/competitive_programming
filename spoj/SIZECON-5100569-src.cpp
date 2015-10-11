#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int t;
    cin>>t;
    int sum;
    sum=0;
    int n;
    int i;
    i=0;
    //for(int i=0;i<t;i++)
    while(i<t)
    {
        cin>>n;
        if(n>0)
        sum=sum+n;
        i=i+1;
    }
    cout<<sum<<endl;
    return 0;
}

