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

template<class T>
class BIT
{
      T *tree;
      int maxVal;
      public:
      BIT(int N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      void update(int idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the cumulative frequency of index idx
      T read(int idx)
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

#define MAX 100001
ll a[MAX];
ll result;
ll temp[MAX];
void merge(int left, int m, int right)
{
    int t_i = 0;
    int i = left, j = m+1;
    while(i<=m && j<=right)
    {
        if(a[i]<a[j])
        {
            temp[t_i++] = a[i];
            result += a[i]*(right - j + 1);
            i++;
        }
        else
            temp[t_i++]=a[j++];
    }

    while(j<=right)
        temp[t_i++] = a[j++];
    while(i<=m)
        temp[t_i++] = a[i++];

    for(int i = 0;i<t_i;i++)
        a[left+i]=temp[i];
}
void sort(int left, int right)
{
    if(left>=right)
        return;
    int m = left + (right - left)/2;
    sort(left,m);
    sort(m+1,right);
    merge(left,m,right);
}
int main()
{
    ll t,n;
    sl(t);
    while(t--)
    {
        sl(n);
        fr(i,0,n)
            sl(a[i]);
        result = 0;
        sort(0,n-1);
        pal(result);
    }
}
