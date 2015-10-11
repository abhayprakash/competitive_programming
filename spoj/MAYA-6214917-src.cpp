#include<iostream>
#include<sstream>
using namespace std;
int a[100]={0};
int calval(string s)
{//cout<<"s="<<s<<endl;
    int toret=0;
    istringstream sin(s);
    string ch;
    while(sin>>ch){//cout<<"ch="<<ch<<" ";
    if(ch=="S")
      toret+=0;
    else if(ch=="-")
      toret+=5;
    else toret+=ch.length();}
    //cout<<"s="<<s<<"="<<toret<<endl;
    return toret;
}
int main()
{
    a[1]=1;a[2]=20;a[3]=360;
    for(int i=4;i<=25;i++)
          a[i]=20*a[i-1];
    int n;
    cin>>n;
    while(n!=0)
    {
        int val=0;string s;
        cin.get();
        //cin.ignore();
        for(int i=n;i>=1;i--)
        {
          getline(cin,s);
          //cout<<"s="<<s<<endl;
          val+=calval(s)*a[i];
          //cout<<"cv="<<calval(s)<<"ai="<<a[i]<<endl;
          //cout<<"val="<<val<<endl;
        }
        cout<<val<<endl;
        cin>>n;
    }
}
