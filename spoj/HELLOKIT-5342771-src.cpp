#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    string s;int n;
    cin>>s;
    while(s!=".")
    {
        string result;
        int l=s.length();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        result+=s;
        cout<<result<<endl;
        for(int i=1;i<l;i++)
        {
            rotate(result.begin(),result.begin()+1,result.end());
            cout<<result<<endl;
        }
    cin>>s;
    }
}