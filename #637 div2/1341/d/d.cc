#include <iostream>
#include <string>

const std::string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
const std::string zero = "0000000";
const int maxn = 2020;
int n, k;
std::string s[maxn];
std::string ans;

int yes[maxn][10];
int minn[maxn], pre[maxn];

int check(std::string a, std::string b) {
	int num = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i] == '0' && b[i] == '1') {
			num++;
		} else if (a[i] == '1' && b[i] == '0') {
			return -1;
		}
	}
	return num;
}

void init() {
	for (int i = 0; i < n; i++) {
		minn[i] = 2000;
		for (int j = 0; j < 10; j++) {
			yes[i][j] = check(s[i], num[j]);
			if (yes[i][j] >= 0) {
				minn[i] = std::min(minn[i], yes[i][j]);
			}
		}
	}
	pre[n-1] = minn[n-1];
	for (int i = n-2; i >= 0; i--) {
		pre[i] = pre[i+1] + minn[i];
	}
//	for (int i = 0; i < n; i++) {
//		std::cout << pre[i] << " \n"[i==n-1];
//	}
}

bool dfs(int pos, int left) {
//	std::cout << pos << ' ' << left << ' ' << ans << '\n';
	if (pos == n) {
		return left == 0;
	}
	if (left < pre[pos]) {
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		int dif = yes[pos][i];
		if (dif >= 0 && dif <= left) {
			ans[pos] = char('0'+i);
			if (dfs(pos+1, left-dif)) {
				return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	init();
	ans = "";
	for (int i = 0; i < n; i++) {
		ans += "0";
	}
	if (dfs(0, k)) {
		std::cout << ans << '\n';
	} else {
		std::cout << "-1\n";
	}
}