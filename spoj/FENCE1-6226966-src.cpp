#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int l;
    cin>>l;
    double a;
    do {
        a=(double)(l*l*16717)/(double)52518;
        cout<<fixed<<setprecision(2)<<a/2.0<<endl;
        cin>>l;
        }while(l!=0);
    return 0;
}


