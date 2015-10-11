#include<iostream>
#include<cstdio>
using namespace std;


#define MAXN 1000

bool done[MAXN+10][MAXN*6+10];
long double dp[MAXN+10][MAXN*6+10];
int n, s;

long double solve(int r, int sum)
{
	if(r == 1)
	{
		if(sum > 0 && sum <= 6)
			return 1.0/6.0;
		else
			return 0;
	}
    if(done[r][sum]!=0)
		return dp[r][sum];

	dp[r][sum] = (solve(r-1, sum-1) + solve(r-1, sum-2) + solve(r-1, sum-3) + solve(r-1, sum-4) + solve(r-1, sum-5) + solve(r-1, sum-6))/6.0;

	done[r][sum] = 1;
	return dp[r][sum];
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%d", &n, &s);
		if(n > MAXN)
		{
			printf("0\n");
			continue;
		}
        printf("%d\n", (int)(100*solve(n,s)));
	}
}
