#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>

#define li int
#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) scanf("%lld",&i)
#define psl(i) printf("%lld ",i)
#define pal(i) printf("%lld\n",i)

#define fr(i,s,n) for(int i=s;i<n;i++)

#define MOD 1000000007

using namespace std;
template<class type>
void s_a(type a[],int n)
{
    fr(i,0,n)
        cin>>a[i];
}

template<class type>
void p_a(type a[],int n)
{
    fr(i,0,n)
        cout<<a[i]<<" ";
    cout<<endl;
}

int bSearch(int key , int len , int arr[])
{
    int left,right,mid;

    left=0; right=len-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==key) return mid;

        if(key<arr[mid]) right=mid-1;
        else left=mid+1;

    }
    return -1;
}
long long mulmod(long long a,long long b)
{
    long long x = 0,y=a%MOD;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%MOD;
        }
        y = (y*2)%MOD;
        b /= 2;
    }
    return x%MOD;
}
long long modulo(long long a,long long b)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=mulmod(x,y);
        }
        y = mulmod(y,y); // squaring the base
        b /= 2;
    }
    return x%MOD;
}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(

{

      if(a<0)return gcd(-a,b);

      if(b<0)return gcd(a,-b);

      return (b==0)?a:gcd(b,a%b);

}

template<class T> inline T lcm(T a,T b)//NOTES:lcm(

{

   if(a<0)return lcm(-a,b);

   if(b<0)return lcm(a,-b);

   return a*(b/gcd(a,b));

}
#define MAX 1000
long double dp[MAX+11][6*MAX+11];
bool done[MAX+11][6*MAX+11] = {false};
long double way(int n, int k)
{
    if(n==1)
    {
        if(k>0 && k<=6)
          return 1.0/6.0;
        else
          return 0;
    }
    if(done[n][k])
        return dp[n][k];
    dp[n][k] = (way(n-1,k-1) + way(n-1,k-2) + way(n-1,k-3) + way(n-1,k-4) + way(n-1,k-5) + way(n-1,k-6))/6.0;
    done[n][k] = 1;
    return dp[n][k];
}
int main()
{
    int t, n, k;
    s(t);
    while(t--)
    {
        s(n);s(k);
        if(n>MAX)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", (int)(100*way(n,k)));
    }
}
