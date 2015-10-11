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

#define De_bug 1
#define pdeb(s,i) if(De_bug)cout<<"DEBUG "<<s<<" "<<i<<endl;

#define MOD 1000000007

using namespace std;

int main()
{
    int t, n;
    s(t);
    while(t--)
    {
        s(n);
        printf("%d\n",n/3);
    }
}
