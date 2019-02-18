#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 1e6 + 7;

int n;
std::string s;
int a[maxn], b[maxn];

int main(int argc, char *argv[]){
	std::cin >> n >> s;
	a[0] = (s[0]=='('?1:-1);
	for (int i = 1; i < n; i++) {
		if (s[i]=='(') {
			a[i] = a[i-1]+1;
		} else {
			a[i] = a[i-1]-1;
		}
	}
	b[n-1] = a[n-1];
	for (int i = n-2; i >= 0; i--) {
		b[i] = std::min(b[i+1], a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			if (b[i] >= 2 && a[n-1] == 2) {
				ans++;
			}
		} else {
			if (b[i] >= -2 && a[n-1] == -2) {
				ans++;
			}
		}
		if (a[i] < 0) {
			break;
		}
	}
	std::cout << ans << '\n';
}