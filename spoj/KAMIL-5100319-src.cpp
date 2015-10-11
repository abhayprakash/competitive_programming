#include<iostream>
#include<string>
using namespace std;int main(){string s;for(int i=0;i<10;i++){cin>>s;int p=1;int n=s.length();for(int j=0;j<n;j++){if(s[j]=='T'||s[j]=='D'||s[j]=='F'||s[j]=='L'){p*=2;continue;}}cout<<p<<endl;}return 0;}
