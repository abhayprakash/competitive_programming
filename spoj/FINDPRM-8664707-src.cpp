#include<stdio.h>
#include<cmath>
#define MAX_NUM 10000001
bool primes[MAX_NUM] = {0}; // false for prime
int primeno[MAX_NUM] = {0};
const int limit = sqrt(MAX_NUM) + 1;
void gen_sieve_primes()
{

	primeno[1] = 1; // temporary
	int n;
	for(n=3;n<limit;n+=2)
    {
        primeno[n] = primeno[n-1] = primeno[n-2];
        if(!primes[n]) // n is prime
        {
            primeno[n]++;
            //for(int m=n*n;m<=MAX_NUM;m=m+(2*n))
            for(int m = n*n;m < MAX_NUM;m+=2*n)
            {
                primes[m]=true;
            }
        }
    }
    for(;n<MAX_NUM;n+=2)
    {
        primeno[n] = primeno[n-1] = primeno[n-2];
        if(primes[n])
            primeno[n]++;
    }
    primeno[1] = 0;
}

void sieve()
{
	unsigned i, j, k;
	primes[0]=0;
	primeno[1] = 1; // temporary
    for(i=3;i<limit;i+=2)
    {
        primeno[i] = primeno[i-1] = primeno[i-2];
        if(!primes[i])
        {
            primeno[i]++;
            k = 2*i;
			for(j=i*i;j<MAX_NUM;j+=k)
				primes[j] = 1;
        }
    }
    //int count = primesum[LMT-1];
    for(;i<MAX_NUM;i+=2)
    {
        primeno[i] = primeno[i-1] = primeno[i-2];
        if(!primes[i])
            primeno[i]++;
    }
    primeno[1] = 0; // though no need to do this
}
int main()
{
    int t,n;
    int ans=0;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=primeno[n]-primeno[n/2];
        printf("%d\n",ans);
    }
}
