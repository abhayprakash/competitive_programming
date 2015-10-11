#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#define getchar_unlocked getchar
#define ll long long
using namespace std;
int inline scan()
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

#define MAX 10000001 // maximum upto primes are required
int LMT = sqrt(MAX) + 1;    // square root of MAX

unsigned flag[MAX/64], total;
int primesum[MAX];

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

int main()
{
    int i, j, k, t, m;
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
    primesum[1] = 0;

    t= scan();
    for(int i =1;i<=t;i++)
    {
        m = scan();
        printf("%d\n",primesum[m] - primesum[m/2]);
    }
    return 0;
}
