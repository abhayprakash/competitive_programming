#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdio>
#include <string>
#include <numeric>
#include <utility>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>

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
#define frR(i,E,S) for(int i=E;i>=S;i--)

#define MOD 1000000007

using namespace std;

int inline inp()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }
    return N;
}

ll mulmod(ll a,ll b, ll c = MOD)
{
    ll x = 0,y=a%c;
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

ll modulo(ll a,ll b, ll c = MOD)
{
    ll x=1,y=a;
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

bool possible(int h, int a[], int n, int m)
{
    int sum = 0;
    fr(i,0,n)
    {
        if((a[i] - h)>0)
            sum += (a[i] - h);
        if(sum >= m)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    s(n); s(m);
    int a[n], maxx = 0;
    fr(i,0,n)
    {
        s(a[i]);
        maxx = max(maxx, a[i]);
    }

    int upper = maxx, lower = 0;
    while(upper>lower)
    {
        int mid = (upper+lower)/2;
        if(possible(mid, a, n, m))
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid - 1;
        }
    }
    if(possible(upper,a,n,m))
        pa(upper);
    else
        pa(upper-1);
}
