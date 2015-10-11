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
#define MAX 50011
using namespace std;
struct Tree{
    int maxv, rval, lval, sum;
};
Tree T[3*MAX];
int a[MAX];

#define maxx( i , j, k) max((i),max((j),(k)))

void build(int root, int i, int j)
{
    if(i==j) {
		T[root].maxv = T[root].sum = T[root].rval = T[root].lval = a[i];
		return;
	}
	int m = (i+j)/2;
	build(2*root, i, m);
	build(2*root+1, m+1, j);
	T[root].sum = T[root*2].sum + T[root*2+1].sum;
	T[root].maxv = maxx(T[2*root].maxv, T[2*root].rval + T[2*root+1].lval, T[2*root+1].maxv);
	T[root].lval = max(T[2*root].lval, T[2*root].sum + T[2*root+1].lval);
	T[root].rval = max(T[2*root].rval + T[2*root+1].sum, T[2*root+1].rval);
}
void query(Tree &res, int root, int l, int r, int i, int j)
{
    if(l==i && r==j) {
		res = T[root];
		return;
	}
	int m = (l + r)/2;
	if(j<=m) query(res, 2*root, l, m, i, j);
	else if(i>m) query(res, 2*root+1, m+1, r, i, j);
	else {
		Tree Left, Right;
		query(Left, 2*root, l, m, i, m);
		query(Right, 2*root+1, m+1, r, m+1, j);
		res.maxv = maxx(Left.maxv, Right.maxv, Left.rval + Right.lval);
		res.sum = Left.sum + Right.sum;
		res.lval = max(Left.lval, Left.sum + Right.lval);
		res.rval = max(Left.rval + Right.sum, Right.rval);
	}
}

int main()
{
    int n, q, x, y;
    Tree result;
    s(n);
    fr(i, 0, n)
        s(a[i]);
    build(1, 0, n-1);
    s(q);
    while(q--)
    {
        s(x); s(y);
        query(result, 1, 0, n-1, x-1, y-1);
        pa(result.maxv);
    }
    return 0;
}
