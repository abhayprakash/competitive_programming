#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int t,x=1;
    cin>>t;
    while(t--)
    {
        long long int r;
        cin>>r;
        cout<<"Case "<<x++<<": "<<fixed<<setprecision(2)<<((4*r*r)+0.25)<<endl;
    }
}

