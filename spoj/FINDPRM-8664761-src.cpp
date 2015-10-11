#include<stdio.h>
#include<cmath>
#define MAX_NUM 10000001
bool primes[MAX_NUM] = {0}; // false for prime
int primeno[MAX_NUM] = {0};
const int limit = sqrt(MAX_NUM) + 1;

void gen_sieve_primes()
{
	unsigned n, m, prod;
	primeno[1] = 1; // temporary
    for(n=3;n<limit;n+=2)
    {
        primeno[n] = primeno[n-1] = primeno[n-2];
        if(!primes[n])
        {
            primeno[n]++;
            prod = 2*n;
			for(m=n*n;m<MAX_NUM;m+=prod)
				primes[m] = 1;
        }
    }
    for(;n<MAX_NUM;n+=2)
    {
        primeno[n] = primeno[n-1] = primeno[n-2];
        if(!primes[n])
            primeno[n]++;
    }
    primeno[1] = 0;
}
int main()
{
    int t,n;
    int ans=0;
    gen_sieve_primes();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=primeno[n]-primeno[n/2];
        printf("%d\n",ans);
    }
}
