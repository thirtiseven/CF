#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string s;
int n, k, x;
int ans[30];

int main(int argc, char *argv[]) {  
	std::fill(ans, ans+30, 0);
	std::cin >> n >> k;
	std::cin >> s;
	int now = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {
			now++;
		} else {
			if (now >= k) {
				ans[int(s[i-1]-'a')] += (now/k);
			}
			now = 1;
		}
	}
	if (now >= k) {
		ans[int(s[n-1]-'a')] += (now/k);
	}
	x = 0;
	for (int i = 0; i < 26; i++) {
		x = std::max(x, ans[i]);
	}	
	std::cout << x << '\n';
}