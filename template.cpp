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

#define pb push_back
#define fr(i,s,n) for(int i=s;i<n;i++)

#define De_bug 0
#define pdeb(s,i) if(De_bug)cout<<"DEBUG "<<s<<" "<<i<<endl;

#define MOD 1000000007

using namespace std;

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

/* on linux systems
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
*/

int main()
{
    int t;
    s(t);
    while(t--)
    {

    }
}
