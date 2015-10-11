#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    printf("Ready\n");
    while(s!="  ")
    {
        if(s=="pq"||s=="qp"||s=="bd"||s=="db")
        printf("Mirrored pair\n");
        else
        printf("Ordinary pair\n");
        getline(cin,s);
    }
    return 0;
}
