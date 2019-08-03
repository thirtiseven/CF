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

int dp1[MAXN][MAXN][13];
int rec[MAXN][MAXN];
int n,m;

void st(){
	for(int i=1;i<=n;i++)
	for(int k=0;(1<<k)<=m;k++){
	for(int j=1;j+(1<<k)-1<=m;j++){
		if(k==0){
			dp1[i][j][k]=rec[i][j];
		}
		else {
			dp1[i][j][k]=min(dp1[i][j][k-1],dp1[i][j+(1<<(k-1))][k-1]);
		}
	}
	}
}

int rmq2dmin(int x,int y,int x1,int y1){
	int k=log2(y1-y+1);
	int mm=min(dp1[x][y][k],dp1[x][y1-(1<<k)+1][k]);
	for(int i=x+1;i<=x1;i++)
		mm=min(mm,min(dp1[i][y][k],dp1[i][y1-(1<<k)+1][k]));
	return mm;
}

int main(int argc, char *argv[]) {  
	int a, b, g, x, y, z;
	std::cin >> n >> m >> a >> b >> g >> x >> y >> z;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rec[i][j] = g;
			g = (g*x+y)%z;
		}
	}
	st();
	long long ans = 0;
	for (int i = 1; i+a-1 <= n; i++) {
		for (int j = 1; j+b-1 <= m; j++) {
			ans += rmq2dmin(i, j, i+a-1, j+b-1);
		}
	}
	std::cout << ans << '\n';
}