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

      //Read at index i
      int readSingle(int idx)
      {
        int sum = tree[idx]; // sum will be decreased
        if (idx > 0) // special case
        {
            int z = idx - (idx & -idx); // make z first
            idx--; // idx is no important any more, so instead y, you can use idx
            while (idx != z) // at some iteration idx (y) will become z
            {
                sum -= tree[idx]; // substruct tree frequency which is between y and "the same path"
                idx -= (idx & -idx);
            }
        }
        return sum;
      }
};

int main()
{
    BIT ttree(10);
    ttree.update(1,10);
    ttree.update(1,-1);
    cout<<ttree.read(10)<<" "<<ttree.read(7)<<" "<<ttree.readSingle(4)<<" "<<ttree.readSingle(7)<<endl;
}
