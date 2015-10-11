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
int mat[311][311];

void change_mat(int a, int b, int n)
{
    fr(i,1,n+1)
        fr(j,1,n+1)
            mat[i][j] = mat[j][i] = min(mat[i][j], mat[i][a]+mat[a][b]+mat[b][j]);
}

int get_new(int n)
{
    int sum = 0;
    fr(i,2,n+1)
        fr(j,1,i)
            sum += mat[i][j];
    return sum;
}

int main()
{
    int n;
    s(n);
    fr(i,1,n+1)
        fr(j,1,n+1)
            s(mat[i][j]);

    /*********FW - Algo*********/
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n;j++)
            for (int k = 1; k<=n; k++)
                if (mat[j][k] > mat[j][i] + mat[i][k])
                    mat[j][k] = mat[j][i] + mat[i][k];
    /***************************/

    int k, a, b, c;
    s(k);
    while(k--)
    {
        s(a);s(b);s(c);
        mat[a][b] = mat[b][a] = min(mat[a][b],c);
        change_mat(a,b,n);
        pa(get_new(n));
    }
}
