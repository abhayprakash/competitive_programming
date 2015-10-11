#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
          cin>>s[i];
        sort(s,s+n);
        bool ans=true;
        for(int i=0;i<n-1;i++)
         {
             if(s[i+1].find(s[i])!=string::npos)
               {
                   ans=false;
                   cout<<"NO\n";
                   break;
               }
         }
        if(ans)
          cout<<"YES\n";
    }
}
