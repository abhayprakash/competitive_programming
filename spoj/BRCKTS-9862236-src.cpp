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

void makeTree(int root, int i, int j)
{
    if(i==j)
    {
        tree[root].sum = tree[root].minsum = (seq[i]=='(' ? 1 : -1);
        return;
    }
    int mid = (i+j)/2;
    makeTree(2*root, i, mid);
    makeTree(2*root+1, mid+1, j);
    tree[root].sum = tree[2*root].sum + tree[2*root+1].sum;
    tree[root].minsum = min(tree[2*root].sum + tree[2*root+1].minsum, tree[2*root].minsum);
}

void update(int root, int i, int j, int index)
{
    if(i==j && i == index)
    {
        tree[root].sum = tree[root].minsum = -tree[root].sum;
        return;
    }
    int mid = (i+j)/2;
    if(index <= mid)
        update(2*root, i, mid, index);
    else
        update(2*root+1, mid+1, j, index);

    tree[root].sum = tree[2*root].sum + tree[2*root+1].sum;
    tree[root].minsum = min(tree[2*root].sum + tree[2*root+1].minsum, tree[2*root].minsum);
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
