#include <iostream>
#include <cstring>

const int maxn = 4e5+7;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int num[30], sub[30];
	memset(num, 0, sizeof(num));
	memset(sub, 0, sizeof(sub));
	char s[maxn];
	int n, k;
	std::cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		num[s[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (num[i] > 0) {
			sub[i] = std::min(num[i], k);
			k -= num[i];
		}
		if (k < 0) break;
	}
	for (int i = 0; i < n; i++) {
		if (sub[s[i]-'a'] > 0) {
			sub[s[i]-'a']--;
		} else {
			std::cout << s[i];
		}
	}
}