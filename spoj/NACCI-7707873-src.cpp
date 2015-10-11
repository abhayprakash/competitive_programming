#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<numeric>
 
#define li int
#define ll long long
#define ull unsigned long int
 
#define s(i) scanf("%d",&i)
#define ps(i) printf("%d ",i)
#define pa(i) printf("%d\n",i)
 
#define sl(i) scanf("%lld",&i)
#define psl(i) printf("%lld ",i)
#define pal(i) printf("%lld\n",i)
 
#define fr(i,s,n) for(int i=s;i<n;i++)
 
using namespace std;
 
ll MOD;
 
void mat_pow(ll M[][30],ll p, ll k)
{
    if(p==1)
        return;
    ll temp[30][30];
    fr(i,0,k)
        fr(j,0,k)
            temp[i][j]=M[i][j];
    mat_pow(temp,p/2,k);
    ll temp2[30][30];
    fr(i,0,k)
        fr(j,0,k)
        {
            temp2[i][j]=0;
            fr(l,0,k)
            {
                temp2[i][j] += (temp[i][l]*temp[l][j])%MOD;
                if(temp2[i][j]>=MOD)
                    temp2[i][j] -= MOD;
            }
        }
 
    if(p & 1)
    {
        fr(i,0,k)
            fr(j,0,k)
            {
                temp[i][j]=0;
                fr(l,0,k)
                {
                    temp[i][j] += (temp2[i][l]*M[l][j])%MOD;
                    if(temp[i][j]>=MOD)
                        temp[i][j] -= MOD;
                }
            }
        fr(i,0,k)
          fr(j,0,k)
            M[i][j]=temp[i][j];
    }
    else
    {
        fr(i,0,k)
          fr(j,0,k)
            M[i][j]=temp2[i][j];
    }
}
 
ll fib(ll n, ll k)
{
    ll mat[30][30];
    fr(i,0,k)
    {
        fr(j,0,k)
        {
            mat[i][j]=0;
            if(i==0)
            {
                mat[i][j]=1;
                continue;
            }
            if(j == i-1)
                mat[i][j]=1;
        }
    }
    //print(mat,k);
    mat_pow(mat,n,k);
    //print(mat,k);
    ll toret = 0;
    fr(i,0,k)
    {
        toret += (mat[0][i]*(k-1-i))%MOD;
        if(toret>=MOD)
            toret -= MOD;
    }
    return toret;
}
 
int main()
{
    ll t,n,l;
    sl(t);
    while(t--)
    {
        sl(n);sl(MOD);sl(l);
        MOD = pow(10,MOD);
        if(l<=n)
        {
            pal((l-1)%MOD);
            continue;
        }
        l -= n;
        pal(fib(l+1,n));
    }
    return 0;
}