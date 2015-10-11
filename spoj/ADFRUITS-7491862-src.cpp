#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int memo[200][200];
char a[200],b[200];
int len(int i,int j)
{
    if(memo[i][j]>=0)
      return memo[i][j];
    if(a[i]==0)
      memo[i][j]=strlen(b+j);
    else if(b[j]==0)
      memo[i][j]=strlen(a+i);
    else if(a[i]==b[j])
      memo[i][j]=len(i+1,j+1) + 1;
    else
      memo[i][j]=min(len(i+1,j),len(i,j+1))+1;
    return memo[i][j];
}
int main()
{
    while(scanf("%s%s",&a,&b)!=EOF)
    {
        for (int i=0; i<=strlen(a); i++)
            for (int j=0; j<=strlen(b); j++)
                memo[i][j] = -1;
        len(0,0);
        for (int i=0,j=0;;)
        {
            if (a[i]==0)
            {
                printf("%s\n",b+j);
                break;
            }
            else if (b[j]==0)
            {
                printf("%s\n",a+i);
                break;
            }
            else if (a[i]==b[j])
            {
                putchar(a[i]);
                i++; j++;
            }
            else if (len(i+1,j)<= len(i,j+1))
            {
                putchar(a[i]);
                i++;
            }
            else
            {
                putchar(b[j]);
            j++;
            }
        }
        //printf("%s\n");
    }
}
