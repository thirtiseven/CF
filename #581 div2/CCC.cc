#include <iostream>
#include <vector>
#include <string>

const int maxn = 102;
const int maxm = 1e6+7;
const int inf = 1000000;

int n, m;
int d[maxn][maxn], num[maxn][maxn][maxn];
int p[maxm];
int yes[maxm];
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	int input;
	std::string s;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> s;
		for(int j = 0; j < n; j++) {
			if (s[j] == '1') {
				d[i][j] = 1;
			} else {
				d[i][j] = inf;
			}
		}
	}
	d[0][0] = 0;
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (i != j) {
					if (d[i][k] + d[k][j] <= d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
	}
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> p[i];
		p[i]--;
	}
	int cnt = 0;
	ans.push_back(p[0]);
	for (int i = 1; i < m; i++) {
		int now = *ans.rbegin();
		while (d[now][p[i]] != i-cnt) {
//			std::cout << now << ' ' << p[i]  << ' ' << d[now][p[i]] << ' ' << i-cnt << ' ' << p[i-1] << ' ' << cnt << '\n';
			ans.push_back(p[i-1]);
			cnt = i-1;
			now = *ans.rbegin();
		}
	}
	if (ans[ans.size()-1] != p[m-1]) {
		ans.push_back(p[m-1]);
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it+1 << ' ';
	}
}