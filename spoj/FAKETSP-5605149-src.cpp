#include<stdio.h>
#include<iostream>
#include<string.h>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    long double a,b,total=0,t1=0,t2=0;
    string s;
    getline(cin,s);
    int l=s.length()-1;
    while(s[l]!='(')
          l--;
    string val(s,l+1,s.length()-l-2);
    l=0;
    while(val[l]!=',')
      l++;
    val.erase(val.begin()+l);
    istringstream input(val);
    input>>t1>>t2;
    while(getline(cin,s))
    {
    int l=s.length()-1;
    while(s[l]!='(')
          l--;
    string val(s,l+1,s.length()-l-2);
    l=0;
    while(val[l]!=',')
      l++;
    val.erase(val.begin()+l);
    istringstream input(val);
    input>>a>>b;
    total+=sqrt((a-t1)*(a-t1)+(b-t2)*(b-t2));
    cout<<"The salesman has traveled a total of "<<fixed<<setprecision(3)<<total<<" kilometers.\n";
    t1=a;t2=b;
    }
}