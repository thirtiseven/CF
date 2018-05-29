#include <iostream>
#include <string>

const int maxn = 123;

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	std::string a[maxn], s;
	for (int i = 1; i <= n; i++) {
		a[i] = ".";
		std::cin >> s;
		a[i] += s;
		a[i] += ".";
	}	
	bool yes = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = 0;
			int ans;
			if (a[i][j] == '*') continue;
			else if (a[i][j] == '.') ans = 0;
			else ans = a[i][j] - '0';

			if (a[i-1][j-1] == '*') cnt++;
			if (a[i-1][j] == '*') cnt++;
			if (a[i-1][j+1] == '*') cnt++;
			if (a[i][j-1] == '*') cnt++;
			if (a[i][j+1] == '*') cnt++;
			if (a[i+1][j-1] == '*') cnt++;
			if (a[i+1][j] == '*') cnt++;
			if (a[i+1][j+1] == '*') cnt++;
			if (ans != cnt) yes = 0;
//			std::cout << a[i][j] << " " << ans << " " << cnt << " " << i << " " << j << '\n';
		}
	}
	std::cout << (yes?"YES":"NO");
}