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
#include<iomanip>
#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)

using namespace std;
unsigned long int fact(int n)
{
    unsigned long int toret = 1;
    for(int i = 2;i<=n;i++)
      toret*=i;
    return toret;
}
int main()
{
     int n,k,sum,nk;
     unsigned long int result;
     while(cin>>n>>k)
     {
         result = fact(n);
         unsigned long int
         sum=0;
         for(int i=0;i<k;i++)
           {
                s(nk);
                result/=fact(nk);
           }
        cout<<result<<endl;
     }
}
