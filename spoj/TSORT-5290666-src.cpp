#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
    return 0;
}




