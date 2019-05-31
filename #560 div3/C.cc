#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 2e5+7;
int ok[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int ans = 0;
	std::fill(ok, ok+maxn, 0);
	int i;
	for (i = 0; i < n;) {
		while (i < n-1 && s[i] == s[i+1]) {
			ok[i] = 1;
			ans++;
			i++;
		}
		i += 2;
	}
	std::string res = "";
	for (int i = 0; i < n; i++) {
		if (!ok[i]) {
			res += s[i];
		}
	}
	if ((n-ans)%2 == 1) {
		ans++;
		res.erase(res.length()-1);
	}
	std::cout << ans << '\n' << res << '\n';
} 