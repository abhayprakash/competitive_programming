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

class BIT
{
      int *tree;
      int MaxVal;
      public:
      BIT(int N)
      {
              tree = new int[N+1];
              memset(tree,0,sizeof(int)*(N+1));
              MaxVal = N;
      }
      void update(int idx ,int val)
      {
        while (idx <= MaxVal)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
      }
      //Returns the cumulative frequency of index idx
      int read(int idx)
      {
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
      }
};

int main()
{
    int t, n, x, y, q;
    float pos;
    s(t);
    while(t--)
    {
        s(n);
        BIT tree(20007);
        fr(i,0,n)
        {
            s(x);s(y);
            tree.update(x+1, 1);
            s(x);s(y);
            tree.update(x+1, -1);
        }
        s(q);
        while(q--)
        {
            s(n);
            if(n)
            {
                s(x);s(y);
                tree.update(x+1, 1);
                s(x);s(y);
                tree.update(x+1, -1);
            }
            else
            {
                cin>>pos;
                pdeb("read for ", ceil(pos));
                pa(tree.read(ceil(pos)));
            }
        }
    }
}
