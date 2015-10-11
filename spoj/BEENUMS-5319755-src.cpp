#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int main()
{
    ofstream savein("beenum.txt");
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        int i=1;long int prod;
        prod=3*i*(i-1)+1;
        while(prod<n)
        {
            i++;
            prod=3*i*(i-1)+1;
        }
        if(prod==n)
        cout<<"Y\n";
        else
        cout<<"N\n";
        scanf("%d",&n);
    }
    return 0;
}
