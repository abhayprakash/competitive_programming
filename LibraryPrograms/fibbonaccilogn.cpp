#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define li int
#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) cin>>i
#define psl(i) cout<<i<<" "
#define pal(i) cout<<i<<"\n"

#define fr(i,s,n) for(int i=s;i<n;i++)

//#define MOD 1000000007

ll MOD;
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

long long mulmod(long long a,long long b, long long c = MOD)
{
    long long x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
long long modulo(long long a,long long b, long long c = MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=mulmod(x,y);
        }
        y = mulmod(y,y);
        b /= 2;
    }
    return x%c;
}

template<class T> inline T gcd(T a, T b)
{
	while(b)
        b^=a^=b^=a%=b;
	return a;
}

template<class T> inline T lcm(T a,T b)
{
   if(a<0)return lcm(-a,b);
   if(b<0)return lcm(a,-b);
   return a*(b/gcd(a,b));
}

ll A[2][2] = {1,1,
              1,0};
ll mult[2][2] = {1,1,
                 1,0};
ll temp[2][2];
void mat_pow(ll n)
{
    if(n == 1)
        return;

    mat_pow(n/2);

    ll value = 0;

    fr(i,0,2)
        fr(j,0,2)
            temp[i][j] = mult[i][j];

    fr(i,0,2)
        fr(j,0,2)
        {
            value = 0;
            fr(k,0,2)
                value += (temp[i][k] * temp[k][j])%MOD;
            mult[i][j] = value%MOD;
        }

    if(n&1)
    {
        fr(i,0,2)
            fr(j,0,2)
                temp[i][j] = mult[i][j];
        fr(i,0,2)
            fr(j,0,2)
            {
                value = 0;
                fr(k,0,2)
                    value += (temp[i][k] * A[k][j])%MOD;
                mult[i][j] = value%MOD;
            }
    }
}

ll fib(ll n)
{
    A[0][0] = 1;
    A[0][1] = 1; //{1,1,
    A[1][0] = 1;
    A[1][1] = 0;
    mult[0][0] = 1;
    mult[0][1] = 1; //{1,1,
    mult[1][0] = 1;
    mult[1][1] = 0;
    temp[0][0] = 0;
    temp[0][1] = 0; //{1,1,
    temp[1][0] = 0;
    temp[1][1] = 0;
    ll fib[2] = {1, 0};
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    mat_pow(n-1);
    return ((mult[0][0] * fib[0])%MOD + (mult[0][1] * fib[1])%MOD)%MOD;
}

int main()
{
    int t;
    ll n;
    s(t);
    while(t--)
    {
        sl(n); sl(MOD);
        pal(fib(n));
    }
}
