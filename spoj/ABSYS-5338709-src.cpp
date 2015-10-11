#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int a,b,c;
        char u1,u2;
        string input,useless;
        fflush(stdin);
        cin.get();
        getline(cin,input);
        istringstream inputstring(input);
        int p_m=input.find("machula");
        int p_e=input.find("=");
        int p_p=input.find("+");
        if(p_m<p_p)
        {
            inputstring>>useless>>u1>>b>>u2>>c;
            a=c-b;
        }
        else if(p_m<p_e)
        {
            inputstring>>a>>u1>>useless>>u2>>c;
            b=c-a;
        }
        else
        {
            inputstring>>a>>u1>>b;
            c=a+b;
        }
        printf("%d + %d = %d\n",a,b,c);
    }
    return 0;
}
