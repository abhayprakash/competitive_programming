#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int count[8]={0};
        int n;
        string seq;
        scanf("%d",&n);
        cin>>seq;
        string temp;
        temp[3]='\0';
        for(int i=0;i<38;i++)
        {
            temp[0]=seq[i];
            temp[1]=seq[i+1];
            temp[2]=seq[i+2];
            if(temp[0]=='T'&&temp[1]=='T'&&temp[2]=='T')
              count[0]++;
            else if(temp[0]=='T'&&temp[1]=='T'&&temp[2]=='H')
              count[1]++;
            else if(temp[0]=='T'&&temp[1]=='H'&&temp[2]=='T')
              count[2]++;
            else if(temp[0]=='T'&&temp[1]=='H'&&temp[2]=='H')
              count[3]++;
            else if(temp[0]=='H'&&temp[1]=='T'&&temp[2]=='T')
              count[4]++;
            else if(temp[0]=='H'&&temp[1]=='T'&&temp[2]=='H')
              count[5]++;
            else if(temp[0]=='H'&&temp[1]=='H'&&temp[2]=='T')
              count[6]++;
            else if(temp[0]=='H'&&temp[1]=='H'&&temp[2]=='H')
              count[7]++;
        }
      printf("%d %d %d %d %d %d %d %d %d\n",n,count[0],count[1],count[2],count[3],count[4],count[5],count[6],count[7]);
    }
    return 0;
}

