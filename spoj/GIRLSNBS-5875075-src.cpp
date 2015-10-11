#include<iostream>
using namespace std;
int main()
{
    int g,b;
    cin>>g>>b;
    while(g!=-1)
    {
        int m=min(g,b);
        int s=max(g,b);
        if(s%(m+1)==0)
          cout<<s/(m+1)<<endl;
        else
          cout<<s/(m+1)+1<<endl;
        cin>>g>>b;
    }
}
