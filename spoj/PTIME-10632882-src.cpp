#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstring>

#define ll long long int
#define ull unsigned long int

#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)

#define sl(i) scanf("%lld",&i)
#define psl(i) printf("%lld ",i)
#define pal(i) printf("%lld\n",i)

#define fr(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define MOD 1000000007

using namespace std;

//usage: vector<int> p; getPrime(p,13);
void getPrime(vector<int> &primes, int lessThanThis)
{
    int p[lessThanThis];
    memset(p,0,sizeof(p));
    p[0]=1;
    fr(i,2,sqrt(lessThanThis))
        if(!p[i])
            for(int j = i*i;j<lessThanThis;j += i)
                p[j]=1;
    for(int i = 2;i<lessThanThis;i++)
        if(!p[i])
            primes.pb(i);
}

void printAns(int n)
{
    vector<int> primes;
    getPrime(primes, 20000);
    //cout<<primes.size()<<endl<<primes[primes.size()-1];
    for(int i = 0; primes[i] <= n;i++)
    {
        if(i != 0)
            printf(" * ");
        if(primes[i] > n/2)
            printf("%d^1", primes[i]);
        else
        {
            int power = 0;
            int rem = n;
            while(rem)
            {
                rem = rem/primes[i];
                power += rem;
            }
            printf("%d^%d",primes[i], power);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    s(n);
    printAns(n);
}
