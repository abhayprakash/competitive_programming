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

/** Sieve:
*   stores primes in "primes[]"
**/
#define MAX 100000000 // maximum upto primes are required
#define LMT 10000    // square root of MAX

unsigned flag[MAX/64], total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	flag[0]=0;
	pa(2);
	for(i=3;i<LMT;i+=2)
		if(!chkC(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				setC(j);
	j = 0;
	for(i=3;i<MAX;i+=2)
        if(!chkC(i))
        {
            j++;
            if(j==100)
            {
                pa(i);
                j = 0;
            }
        }
}
/** /Sieve **/

int main()
{
    sieve();
}
