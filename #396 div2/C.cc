#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int a[30];
char str[1010];
int dp[1010];

int judge(int i, int j)
{
	for(int k = i-j+1; k <= i; k++)
	{
		if(a[str[k]-'a'] < j)
			return 0;
	}
	return 1;
}

int main()
{
	int n, i, j;
	int minn[1010];
	scanf("%d", &n);
	scanf("%s", str+1);
	for(i = 0; i < 26; i++)
	{
		scanf("%d", &a[i]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	minn[0] = 0;
	int maxx = 0;
	for(i = 1; i <= n; i++)
	{
		minn[i] = inf;
		for(j = 1; j <= i; j++)
		{
			if(judge(i, j))
			{
				if(dp[i-j])
					maxx = max(j, maxx);
				dp[i] = (dp[i] + dp[i-j])%mod;
				minn[i] = min(minn[i], minn[i-j]+1);
			}
		}
	}
	printf("%d\n%d\n%d\n", dp[n], maxx, minn[n]);
	return 0;
}