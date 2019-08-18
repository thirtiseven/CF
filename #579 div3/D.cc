#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 2e5+7;

std::string s, t;
int a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> s >> t;
	int pos = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[pos]) {
			a[pos] = i;
			pos++;
		}
	}
	pos = t.length()-1;
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == t[pos]) {
			b[pos] = i;
			pos--;
		}
	}
	int ans = 0;
	for (int i = 0; i < t.length()-1; i++) {
		ans = std::max(ans, b[i+1]-a[i]-1);
	}
	ans = std::max(ans, b[0]);
	ans = std::max(ans, int(s.length()-a[t.length()-1]-1));
	std::cout << ans << '\n';
}