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
 
int menp[511][511], manm[511], womm[511], freeman[511], freewom[511], rank[511][511];
void stable(int n)
{
    fr(i,0,510)
    {
        freeman[i] = 1;
        freewom[i] = 1;
    }
    int freeMCnt = n, chosen_man, prop_wom;
    while(freeMCnt)
    {
        //cout<<"FreeCnt: "<<freeMCnt<<endl;
        fr(i,1,n+1)
            if(freeman[i])
            {
                chosen_man = i;
                //cout<<"chosen: "<<chosen_man<<endl;
                break;
            }
        fr(i,1,n+1)
        {
            prop_wom = menp[chosen_man][i];
            if(freewom[prop_wom])
            {
                manm[chosen_man] = prop_wom;
                womm[prop_wom] = chosen_man;
                freeman[chosen_man] = 0;
                freewom[prop_wom] = 0;
                freeMCnt--;
                break;
            }
            else if(rank[prop_wom][chosen_man] < rank[prop_wom][womm[prop_wom]]) // change sign acc to highness of ranking
            {
                freeman[womm[prop_wom]] = 1;
                manm[chosen_man] = prop_wom;
                womm[prop_wom] = chosen_man;
                freeman[chosen_man] = 0;
                break;
            }
        }
        //cout<<"OutFreeCnt: "<<freeMCnt<<endl;
    }
}
int main()
{
    int t, n, man_i, wom_i;
    s(t);
    while(t--)
    {
        s(n);
        fr(i,1,n+1)
        {
            s(wom_i);
            fr(j,1,n+1)
            {
                s(man_i);
                rank[wom_i][man_i] = j;
            }
        }
        fr(i,1,n+1)
        {
            s(man_i);
            fr(j,1,n+1)
            {
                s(wom_i);
                menp[man_i][j] = wom_i;
            }
        }
        stable(n);
        fr(i,1,n+1)
        {
            ps(i);pa(manm[i]);
        }
    }
    return 0;
}