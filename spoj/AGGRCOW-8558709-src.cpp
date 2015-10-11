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
#define MAX 1000001
int a[MAX];
bool poss(int n, int c, int gap)
{
    int last_placed = a[0], placed_count = 1;
    for(int i = 1; i < n && placed_count < c; i++)
    {
        if(a[i] - last_placed >= gap)
        {
            last_placed = a[i];
            placed_count++;
        }
    }
    if(placed_count == c)
        return true;
    return false;
}
int main()
{
    int t, n, c;
    s(t);
    while(t--)
    {
        s(n); s(c);
        fr(i,0,n)
            s(a[i]);
        sort(a,a+n);
        int midD, maxD = 1000000001, minD = 0, ans = 0;
        while(minD < maxD)
        {
            midD = (maxD + minD)/2;
            if(poss(n,c,midD)){
                minD = midD + 1;
                ans = midD;
            }
            else
                maxD = midD;
        }
        if(poss(n,c,minD))
            ans = minD;
        pa(ans);
    }
}
