#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int m[n],f[n];
        for(int i=0;i<n;i++)
        scanf("%d",&m[i]);
        for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
        vector<int>mv(m,m+n);
        vector<int>fv(f,f+n);
        sort(mv.begin(),mv.end());
        sort(fv.begin(),fv.end());
        int prod=0;
        for(int i=0;i<n;i++)
        prod+=mv[i]*fv[i];
        printf("%d\n",prod);
    }
    return 0;
}
