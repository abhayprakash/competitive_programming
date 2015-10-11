#include<iostream>
#include<stdio.h>
using namespace std;
#include<bitset>
#include<cmath>
int main()
{
    bitset<100001> b;
    b.flip();
    b.reset(0);
    b.reset(1);
    int i=2;
    while(i<=179)
    {
        //cout<<"in:"<<i<<endl;
        if(b.test(i))
        {
            int p=2;
            int d=p*i;
            while(d<32000)
            {
                b.reset(d);
                p++;
                d=p*i;
            }
        }
        i++;
    }
    int bp[3432],cnt=0;
    for(int j=0;j<32000;j++)
    if(b.test(j))
    {
        bp[cnt++]=j;
    }

    int t;
    //cin>>t;
    scanf("%d",&t);
    int m[t],n[t];
    for(int j=0;j<t;j++)
    //cin>>m[j]>>n[j];
    scanf("%d%d",&m[j],&n[j]);

    for(int j=0;j<t;j++)
    {
        int zr=m[j],max=n[j];
        bool s[max-zr+1];
        for(int st=0;st<=max-zr;st++)
        s[st]=true;
        if(zr==0)
        {s[0]=false;s[1]=false;}
        else if(zr==1)
        {s[0]=false;}
        int fac=sqrt(max);

        for(int k=0;bp[k]<=fac;k++)
        {
            int pd=zr/bp[k];
            if(pd==0||pd==1) pd=2;
            int d=pd*bp[k]-zr;
            int bn;
            while(d<=max-zr)
            {//cout<<d<<"*\n";
                if(d>=0) bn=d;
                s[bn]=false;
                //cout<<"here\n";
                pd++;
                d=pd*bp[k]-zr;
            }
        }
        for(int l=0;l<=max-zr;l++)
        {
            if(s[l])
            //cout<<l+zr<<endl;
            printf("%d\n",l+zr);
        }
        printf("\n");
    }
    return 0;
}
