#include <iostream>
#include <cmath>

using namespace std;
const int maxn = 100010;
typedef long long ll;
int a[maxn];
int b[maxn];
ll sum[maxn];
ll sum2[maxn];
int vis[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)scanf("%d",&a[i]);
	for (int i = 1; i <= n; ++i){
		sum[i] = sum[i-1] + a[i]*a[i == n ? 1 : (i+1)];
		sum2[i] = sum2[i-1] + a[i];
	}

	for (int i = 1; i <= m; ++i)scanf("%d",&b[i]);
	ll ans = 0ll;
	ll sumcnt = 0ll;
	for (int i = 1; i <= m; ++i){
		ans += (sum2[n] - a[b[i]] - sumcnt) * a[b[i]];
		sumcnt += a[b[i]];
		vis[b[i] ] = 1;
		int down;
		if (b[i] == 1)down = n;
		else down = b[i]-1;
		vis[down] = 1;
	}
	for (int i = 1; i <= n; ++i){
		if (vis[i])continue;
		ans += a[i]*a[i == n ? 1 : (i+1)];

	}
	printf("%I64d\n",ans);
	return 0;
}