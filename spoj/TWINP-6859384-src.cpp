#include<iostream>
#include<fstream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
#define ph printf("here\n");
#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)

using namespace std;
bitset<2*10000000> p;//0==prime

int s1[100011], s_i=0;
int main()
{
    fr(i,3,4291)
      {
         if(!p[i])
           for(int j=i*i;j<18409202;j=j+2*i)
             p[j]=1;
         i++;
      }

    s1[s_i]=3;
    s_i++;
    int i=1;
    while(s_i<100000)
    {
      if(!p[6*i-1] && !p[6*i+1])
      {
        s1[s_i]=6*i-1;
        s_i++;
      }
      i++;
    }
    int t,n;
    s(t);
    while(t--)
    {
        s(n);
        ps(s1[n-1]);
        pa(s1[n-1]+2);
    }
    return 0;
}
