#include <iostream>
#include <string>
#include <vector>

const int maxn = 2e5+7;

int T, n;
std::string s;
int a[maxn], b[maxn];
std::vector<int> c;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		for (int i = 0; i < n; i++) {
			a[i] = 0;
			b[i] = 0;
		}
		c.clear();
		int cnt = 0;
		for (int i = 0; i < n-1; i++) {
			if (s[i] == '<') {
				cnt++;
			}
		}
		int now = n-cnt+1;
		for (int i = 0; i < n-1; i++) {
			if (s[i] == '<') {
				a[i+1] = now;
				now++;
			}
		}
		now = 1;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] == 0) {
				a[i] = now;
				now++;
			}
		}
		int tot = 1;
		for (int i = 1; i < n-1; i++) {
			if (s[i] != s[i-1]) {
				if (s[i-1] == '<') {
					c.push_back(tot);
				}
				tot = 1;
			} else {
				tot++;
			}
		}
		c.push_back(tot);
		int idx = 0;
		now = n;
		for (int i = 0; i < n;) {
			if (s[i] == '<') {
				for (int j = 1; j <= c[idx]; j++) {
					b[i+j] = now-c[idx]+j;
				}
				i += c[idx];
				now -= (c[idx]);
				idx++;
			} else {
				i++;
			}
		}
		now = 1;
		for (int i = n-1; i >= 0; i--) {
			if (b[i] == 0) {
				b[i] = now;
				now++;
			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << b[i] << ' ';
		}
		std::cout << '\n';
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << ' ';
		}
		std::cout << '\n';
	}
} 