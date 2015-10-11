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
int mod(int x)
{
    if(x < 0)
        return -x;
    return x;
}
int a[1011], b[1011];
int main()
{
    //cout<<mod(3 - 5 );
    int t, n, m;
    s(t);
    while(t--)
    {
        s(n);
        fr(i,0,n)
            s(a[i]);
        int ans = 10000011, low_b, up_b;
        s(m);
        fr(i,0,m)
            s(b[i]);
        sort(a,a+n);
        sort(b,b+m);
        b[m] = ans;// just used to put a high value
        fr(i,0,n)
        {
            low_b = lower_bound(b,b+m,a[i])-b;
            ans = min(ans, mod(b[low_b] - a[i]));
            if(low_b > 0)
                ans = min(ans, mod(b[low_b -1] - a[i]));
            if(low_b < m-1)
                ans = min(ans, mod(b[low_b + 1] - a[i]));
        }
        pa(ans);
    }
}
