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

char mat[70][70] = {0};
int marked[70][70];
int ans, global_ans;
void get_ans(int i, int j, char c, int & count)
{
    count++;
    int this_time; marked[i][j] = 1;
    if(mat[i][j+1] == char((int)c+1) && !marked[i][j+1])
    {
        this_time = count;
        get_ans(i,j+1,mat[i][j+1],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i-1][j+1] == char((int)c+1) && !marked[i-1][j+1])
    {
        this_time = count;
        get_ans(i-1,j+1,mat[i-1][j+1],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i-1][j] == char((int)c+1) && !marked[i-1][j])
    {
        this_time = count;
        get_ans(i-1,j,mat[i-1][j],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i-1][j-1] == char((int)c+1) && !marked[i-1][j-1])
    {
        this_time = count;
        get_ans(i-1,j-1,mat[i-1][j-1],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i][j-1] == char((int)c+1) && !marked[i][j-1])
    {
        this_time = count;
        get_ans(i,j-1,mat[i][j-1],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i+1][j-1] == char((int)c+1) && !marked[i+1][j-1])
    {
        this_time = count;
        get_ans(i+1,j-1,mat[i+1][j-1],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i+1][j] == char((int)c+1) && !marked[i+1][j])
    {
        this_time = count;
        get_ans(i+1,j,mat[i+1][j],this_time);
        ans = max(ans, this_time);
    }
    if(mat[i+1][j+1] == char((int)c+1) && !marked[i+1][j+1])
    {
        this_time = count;
        get_ans(i+1,j+1,mat[i+1][j+1],this_time);
        ans = max(ans, this_time);
    }
    return;
}

int main()
{
    int n, m, cs = 1, this_time_ans;
    while(1)
    {
        global_ans = 0;
        n = inp(); m = inp();
        if(n == 0 && m == 0)
            break;
        fr(i,0,n+11)
            fr(j,0,m+11)
            {
                marked[i][j] = 0;
                mat[i][j] = 'x';
            }
        fr(i,1,n+1)
        {
            fr(j,1,m+1)
            {
                mat[i][j] = getchar_unlocked();
            }
            getchar_unlocked();
        }
        int temp;
        bool A_hai = false;
        fr(i,1,n+1)
        {
            fr(j,1,m+1)
            {
                if(mat[i][j] == 'A')
                {
                    A_hai = true;
                    ans = 0; temp = 0;
                    get_ans(i,j,'A',temp);
                    global_ans = max(global_ans, ans);
                }
            }
        }
        if(A_hai == true && global_ans == 0)
            printf("Case %d: %d\n",cs, 1);
        else
            printf("Case %d: %d\n",cs, global_ans);
        cs++;
    }
}
