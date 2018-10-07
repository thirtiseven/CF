#include <iostream>
#include <cstring>

int t,a[50];
long long l,r,dp[50][10];

int dfs(int pos,int tot,bool limit){
	if(tot>3) return 0;
	if(!pos) return 1;
	if(!limit && dp[pos][tot]!=-1) {
		return dp[pos][tot];
	}
	long long ret = 0;
	int up = (limit?a[pos]:9);
	ret = dfs(pos-1, tot, limit && (a[pos]==0));
	for (int i=1;i<=up;i++) {
		ret += dfs(pos-1, tot+1, limit && (a[pos]==i));
	}
	if (!limit) {
		dp[pos][tot]=ret;
	}
	return ret;
}

long long solve(long long x) {
	memset(dp, -1, sizeof(dp));
	int p = 0;
	while (x) {
		a[++p]=x%10;
		x/=10;
	}
	return dfs(p, 0, 1);
}

int main(int argc, char *argv[]) {
	std::cin >> t;
	while (t--) {
		std::cin >> l >> r;
		std::cout << solve(r)-solve(l-1) << '\n';
	}
	return 0;
}