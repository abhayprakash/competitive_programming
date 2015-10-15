/** Sieve:
*   stores primes in "primes[]"
**/
#define MAXPR 78500 // maximum number of primes
#define MAX 1000000 // maximum upto primes are required
#define LMT 1000    // square root of MAX

unsigned flag[MAX/64], total;
ll primes[MAXPR];

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
	unsigned i, j, k;
	flag[0]=0;
	for(i=3;i<LMT;i+=2)
		if(!chkC(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				setC(j);
	primes[(j=0)++] = 2;
	for(i=3;i<MAX;i+=2)
		if(!chkC(i))
			primes[j++] = i;
	total = j;
}
/** /Sieve **/
