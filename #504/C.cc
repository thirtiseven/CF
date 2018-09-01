#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

const int maxn = 2e5+7;

std::string s;
int n, k;
int vis[maxn];
int ans[maxn];
std::stack<int> del;

int main(int argc, char *argv[]) {  
	std::fill(vis, vis+maxn, 0);
	std::fill(ans, ans+maxn, 0);
	std::cin >> n >> k >> s;
	int need = (n-k)/2;
	ans[0] = 1;
	if (need > 0) {
		vis[0] = 1;
		del.push(ans[0]);
		need--;
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '(') {
			ans[i] = ans[i-1] + 1;
			if (need > 0) {
				vis[i] = 1;
				del.push(ans[i]);
				need--;
			}
		} else {
			ans[i] = ans[i-1] - 1;
			if (!del.empty() && del.top() == ans[i]+1) {
				vis[i] = 1;
				del.pop();
			}
		}
//		std::cout << i << " " << vis[i] << '\n';
	}
	int lab = del.size()-1;
	for (int i = 0; i < s.length(); i++) {
		if (!vis[i]) {
			std::cout << s[i];
		}
	}
}