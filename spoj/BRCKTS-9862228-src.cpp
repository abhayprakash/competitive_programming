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

struct node{
    int sum, minsum;
};

#define NMAX 32768
#define TMAX 65536

char seq[NMAX];
node tree[TMAX];

void makeTree(int Node, int i, int j) {
	if(i==j) {
		tree[Node].sum = tree[Node].minsum = (seq[i]=='(' ? 1 : -1);
		return;
	}
	int m = (i+j)/2;
	makeTree(2*Node, i, m);
	makeTree(2*Node+1, m+1, j);
	tree[Node].sum = tree[2*Node].sum + tree[2*Node+1].sum;
	tree[Node].minsum = min(tree[2*Node].minsum, tree[2*Node].sum + tree[2*Node+1].minsum);
}

void update(int Node, int i, int j, int idx) {
	if(i==j) {
		tree[Node].sum = tree[Node].minsum = -tree[Node].sum;
		return;
	}
	int m = (i+j)/2;
	if(idx<=m) update(2*Node, i, m, idx);
	else update(2*Node+1, m+1, j, idx);
	tree[Node].sum = tree[2*Node].sum + tree[2*Node+1].sum;
	tree[Node].minsum = min(tree[2*Node].minsum, tree[2*Node].sum + tree[2*Node+1].minsum);
}

int main()
{
    int n;
    fr(t,1,11)
    {
        n = inp();

        scanf("%s",seq);
        makeTree(1,0,n-1);

        printf("Test %d:\n",t);
        int m, index;
        m = inp();
        while(m--)
        {
            index = inp();
            if(!index)
            {
                if(tree[1].sum == 0 && tree[1].minsum == 0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                index--;
                update(1, 0, n-1,index);
            }
        }
    }
}
