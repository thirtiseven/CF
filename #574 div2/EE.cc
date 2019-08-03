#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 3003
int rec[MAXN][MAXN];
int dp[MAXN][MAXN][10][10];
//dp-->max
//dp1-->min
int n,m;
int maxm(int a,int b,int c,int d){
	if(a<b)a=b; if(a<c)a=c; if(a<d)a=d;
	return a;
}
int minm(int a,int b,int c,int d){
	if(b<a)a=b; if(c<a)a=c; if(d<a)a=d;
	return a;
}
void st()
{
	for(int k=0;(1<<k)<=n;k++)
	for(int l=0;(1<<l)<=m;l++)
	for(int i=1;i+(1<<k)-1<=n;i++)
	for(int j=1;j+(1<<l)-1<=m;j++)
	{
		if(!k&&!l){
			dp[i][j][k][l]=rec[i][j];
		}
		else if(k==0){
			dp[i][j][k][l]=max(dp[i][j][k][l-1],dp[i][j+(1<<(l-1))][k][l-1]);
		}
		else if(l==0){
			dp[i][j][k][l]=max(dp[i][j][k-1][l],dp[i+(1<<(k-1))][j][k-1][l]);
		}
		else {
		dp[i][j][k][l]=maxm(dp[i][j][k-1][l-1],dp[i+(1<<(k-1))][j][k-1][l-1],
							dp[i][j+(1<<(l-1))][k-1][l-1],dp[i+(1<<(k-1))][j+(1<<(l-1))][k-1][l-1]);
		}
	}
}
int rmq2dmax(int x,int y,int x1,int y1){
	int k=log(x1-x+1)/log(2);
	int l=log(y1-y+1)/log(2);
	return maxm(dp[x][y][k][l],dp[x1-(1<<k)+1][y][k][l],
				dp[x][y1-(1<<l)+1][k][l],dp[x1-(1<<k)+1][y1-(1<<l)+1][k][l]);
}

int main(int argc, char *argv[]) {  
	int a, b, g, x, y, z;
	std::cin >> n >> m >> a >> b >> g >> x >> y >> z;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rec[i][j] = g;
			g = (g*x+y)%z;
//			std::cerr << rec[i][j] << ' ';
		}
//		std::cerr << '\n';
	}
	st();
	long long ans = 0;
	for (int i = 1; i+a-1 <= n; i++) {
		for (int j = 1; j+b-1 <= m; j++) {
			ans += rmq2dmax(i, j, i+a-1, j+b-1);
			std::cerr << rmq2dmax(i, j, i+a-1, j+b-1) << ' ';
		}
		std::cerr << '\n';
	}
	std::cout << ans << '\n';
}