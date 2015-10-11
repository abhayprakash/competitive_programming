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
#include<cstring>
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

struct conn{
    ll n, m;
};

bool myfn(conn i, conn j)
{
    if(i.n>j.n)
        return false;
    else if(i.n < j.n)
        return true;
    else if(i.m > j.m)
        return false;
    return true;
}

template<class T>
class BIT
{
      T *tree;
      ll maxVal;
      public:
      BIT(ll N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      void update(ll idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the cumulative frequency of index idx
      T read(ll idx)
      {
        T sum=0;
        while (idx>0)
        {
              sum += tree[idx];
              idx -= (idx & -idx);
        }
        return sum;
      }
};

int main()
{
    ll t,m,n,k,sum,u,v;
    sl(t);
    fr(cn,1,t+1)
    {
        sum = 0;
        sl(n);sl(m);sl(k);
        vector<pair<long long, long long> > bridges(k);
        fr(i,0,k)
        {
            scanf("%lld %lld",&u,&v);
            bridges[i] = pair<ll,ll>(u,v);
        }
        sort(bridges.begin(),bridges.end());
        BIT<ll> rec(m);
        fr(i,0,k)
        {
            rec.update(bridges[i].second,1);
            sum += rec.read(m) - rec.read(bridges[i].second);
        }
        printf("Test case %d: %lld\n",cn,sum);
    }
}
