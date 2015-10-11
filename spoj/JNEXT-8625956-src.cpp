#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdio>
#include <string>
#include <numeric>
#include <utility>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <functional>

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

#define getchar getchar_unlocked

int inline inp()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }
    return N;
}

int main()
{
    int t, n;
    t = inp();
    while(t--)
    {
        n = inp();
        int a[n];
        fr(i,0,n)
            a[i] = inp();
        if(next_permutation(a,a+n))
        {
            fr(i,0,n)
                putchar_unlocked(a[i] + '0');
            putchar_unlocked(10);
        }
        else
            pa(-1);
    }
}

