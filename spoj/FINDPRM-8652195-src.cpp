#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#define getchar_unlocked getchar
#define ll long long
using namespace std;
ll inline scan()
{
    ll N = 0;
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

#define MAX 10000011 // maximum upto primes are required
ll LMT = sqrt(10000011) + 1;    // square root of MAX

unsigned flag[MAX/64], total;
ll primesum[MAX];

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	flag[0]=0;
	primesum[1] = 1; // temporary
    for(i=3;i<LMT;i+=2)
    {
        primesum[i] = primesum[i-1] = primesum[i-2];
        if(!chkC(i))
        {
            primesum[i]++;
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				setC(j);
        }
    }
    //int count = primesum[LMT-1];
    for(;i<MAX;i+=2)
    {
        primesum[i] = primesum[i-1] = primesum[i-2];
        if(!chkC(i))
            primesum[i]++;
    }
    primesum[1] = 0; // though no need to do this
}
/** /Sieve **/

int main()
{
    sieve();
    //for(int i = 0; i<50;i++)
        //cout<<i<<": "<<primesum[i]<<"\n";
    int t,m;
    t= scan();
    for(int i =1;i<=t;i++)
    {
        m = scan();
        printf("%d\n",primesum[m] - primesum[m/2]);
    }
    return 0;
}
