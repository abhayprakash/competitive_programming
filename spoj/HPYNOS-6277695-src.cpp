#include<iostream>
#include<map>
using namespace std;
int c=0;
map<unsigned long int,int> table;
int fn(unsigned long int n)
{
    if(table[n])
      return -1;
    table[n]=1;
    if(n == 1) return 0;
    c++;
    int sd=0;
    while(n)
    {
        int d=n%10;
        sd+=d*d;
        n/=10;
    }
    return fn(sd);
}
int main()
{
    unsigned long int n;
    cin>>n;
    /*if(n==1)
    cout<<"0";
    else */if(fn(n)==0)
    cout<<c;
    else cout<<"-1";
}
