#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    do{
    if(n==1||m==1)
      printf("%d+%d=%d\n",m,n,m+n);
    else
      printf("%d+%d!=%d\n",m,n,m+n);
    scanf("%d%d",&m,&n);
    }while(m!=-1);
}

