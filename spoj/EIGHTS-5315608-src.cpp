#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int k;
        scanf("%lld",&k);
        string s[4]={"942","192","442","692"};
        if(k%4==0)
        {
            if(k/4!=1)
            printf("%lld",(k/4)-1);
            cout<<s[0]<<endl;
        }
        else
        {
            if(k/4!=0)
            printf("%lld",(k/4));
            cout<<s[k%4]<<endl;
        }
    }
    return 0;
}
