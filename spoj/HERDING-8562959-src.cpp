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

char mat[1011][1011];
int used_trap[1011][1011];
int trap_num = 0, trap_used = 0;
int n, m;
void floodfill(int i, int j)
{
    if(i>=0 && j>=0 && i<n && j<m)
    {
        if(used_trap[i][j])
        {
            trap_num = used_trap[i][j];
            return;
        }
        used_trap[i][j] = trap_num;
        if(mat[i][j]=='N')
            floodfill(i-1,j);
        else if(mat[i][j]=='S')
            floodfill(i+1,j);
        else if(mat[i][j]=='E')
            floodfill(i,j+1);
        else if(mat[i][j]=='W')
            floodfill(i,j-1);
        used_trap[i][j] = trap_num;
    }
}
int main()
{
    s(n); s(m);
    fr(i,0,n)
        scanf("%s",mat[i]);
    fr(i,0,n)
        fr(j,0,m)
        {
            trap_num = trap_used + 1;
            floodfill(i,j);
            if(trap_num > trap_used) trap_used++;
        }
    pa(trap_used);
}
