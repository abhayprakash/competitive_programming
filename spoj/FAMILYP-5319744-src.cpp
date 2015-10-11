#include<iostream>
#include<stdio.h>
using namespace std;
char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int t=1,prod;
        prod=t*(t+1)/2;
        while(prod<n)
        {
            t++;
            prod=t*(t+1)/2;
        }
        printf("%c\n",alpha[(t-1)%26]);
    }
    return 0;
}