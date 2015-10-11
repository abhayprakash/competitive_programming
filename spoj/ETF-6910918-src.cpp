#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<stack>
#include<queue>

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)

using namespace std;
/*int fi(int n)
     {
       int result = n;
       for(int i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }*/
int fi(int n)
{
    int toret=n;
    for(int i=2;i*i<=n;i++){
      if(n%i==0)
        toret=toret-toret/i;
      while(n%i==0)
        n/=i;
    }
    if(n>1) toret-=toret/n;
    return toret;
}
int main()
{
    int t,n;
    s(t);
    while(t--)
    {
        s(n);
        pa(fi(n));
    }
}
