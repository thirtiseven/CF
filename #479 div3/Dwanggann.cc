#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll, int>mp;
int n, l = 100, r = 100;
ll ans[250], a[105];
void dfs(int num,int index, int l, int r) {
	if (num == 0)return;
	if (mp[ans[index] * 2]) {
		mp[ans[index] * 2] = 0;
		ans[index + 1] = ans[index] * 2;
		dfs(num - 1, index + 1, l, r + 1);
	}
	if (mp[ans[index] / 2]) {
		mp[ans[index] / 2] = 0;
		ans[index - 1] = ans[index] / 2;
		dfs(num - 1, index - 1, l - 1, r);
	}
	if (mp[ans[index] / 3]) {
		mp[ans[index] / 3] = 0;
		ans[index + 1] = ans[index] / 3;
		dfs(num - 1, index + 1, l, r + 1);
	}
	if (mp[ans[index] * 3]) {
		mp[ans[index] * 3] = 0;
		ans[index - 1] = ans[index] * 3;
		dfs(num - 1, index - 1, l - 1, r);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = 1;
	}
	ll val = a[1];
	ans[100] = val;
	mp[val] = 0;
	dfs(n-1, 100, 100, 100);
	int flag = 0;
	for (int i = 1;; i++) {
		if (flag&&ans[i] == 0)break;
		if (ans[i])flag = 1;
		else continue;
		cout << ans[i] << " ";
	}
	return 0;
}