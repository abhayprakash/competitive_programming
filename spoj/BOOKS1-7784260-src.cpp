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
#define MAX 511
ll p[MAX];
ll sc[MAX];
ll k, m;
 
int assign(ll val)
{
    //cout<<"val "<<val<<endl;
    int i, j = k-1;
    ll psum;
    for(i = m-1; i>=0; i--)
    {
        if(p[j]>val)
            return 0;
        sc[j]=i;
        psum = p[j--];
        while((j>=i) && (psum + p[j]<=val))
        {
            sc[j]=i;
            psum += p[j--];
        }
    }
    return (j==-1); // that the pages didn't run out before reaching first scribd
}
 
int main()
{
    int t;
    s(t);
    while(t--)
    {
        sl(k);sl(m);
        fr(i,0,k)
          sl(p[i]);
        ll low = 0, high = 5000000000ll, mid;
        while(high - low > 1)
        {
            mid = (high + low)/2;
            if(assign(mid)) high = mid;
            else low = mid;
        }
//cout<<"here"<<high<<endl;
        assign(high);
        psl(p[0]);
        fr(i,1,k)
        {
            if(sc[i]!=sc[i-1])
              printf("/ ");
            psl(p[i]);
        }
        printf("\n");
    }
}