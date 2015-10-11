#include<cstdio>
#include <algorithm>
#define s(i) scanf("%d",&i)
#define pa(i) printf("%d\n",i)
#define fr(i,s,n) for(int i=s;i<n;i++)
using namespace std;char first[55];char friendd[55][55];int get_val(char f, char s){int val = 0;if(f=='S' && s == 'P')val += 2;else if(f=='S' && s == 'S')val++;else if(f=='P' && s == 'R')val += 2;else if(f=='P' && s == 'P')val++;else if(f=='R' && s == 'S')val += 2;else if(f=='R' && s == 'R')val++;return val;}int get_act(int r, int n){int toret = 0;for(int i = 0; i < n; i++){for(int j = 0; j < r; j++){toret += get_val(first[j], friendd[i][j]);}}return toret;}char card[3]={'S','P','R'};int get_max(int r, int n){int max_val = 0, this_time, mmaxx;fr(i,0,r){mmaxx = 0;fr(j,0,3){this_time = 0;fr(k,0,n){this_time += get_val(card[j],friendd[k][i]);}mmaxx = max(mmaxx, this_time);}max_val += mmaxx;}return max_val;}int main(){int r, n;s(r);scanf("%s",first);s(n);for(int i = 0; i < n; i++)scanf("%s",friendd[i]);printf("%d\n",get_act(r,n));printf("%d\n",get_max(r,n));}
