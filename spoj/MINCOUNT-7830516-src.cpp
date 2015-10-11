#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstring>
#define li int
#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) scanf("%llu",&i)
#define psl(i) printf("%llu ",i)
#define pal(i) printf("%llu\n",i)

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

int main()
{
    int t;
    unsigned long long n,k;
    s(t);
    while(t--)
    {
        sl(n);
		if(n==0)
		{
		    pa(0);
		    continue;
        }
		k = (n-1)/3;
		pal((3*k*(k+1))/2 + ((n-1)%3) * (k+1));
    }
}
