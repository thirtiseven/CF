#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int maxn = 1e5+7;
int t, n;
char a[maxn], b[maxn];
std::vector<int> ans;

void rev(int x) {
//	std::cout << "!!!" << a << '\n';
	for (int i = 0; i < x; i++) {
		if (a[i] == '0') {
			a[i] = '1';
		} else {
			a[i] = '0';
		}
	}
//	std::cout << "!!!" << a << '\n';
	std::reverse(a, a+x);
//	std::cout << "!!!" << a << '\n';
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		ans.clear();
		std::cin >> n >> a >> b;
		for (int i = n-1; i >= 0; i--) {
			if (b[i] != a[i]) {
				if (a[0] == b[i]) {
					ans.push_back(1);
					rev(1);
//					std::cerr << 1 << ' ' << a << '\n';
				}
				ans.push_back(i+1);
				rev(i+1);
//				std::cerr << i+1 << ' ' << a << '\n';
			}
		}
		std::cout << ans.size();
		for (int i = 0; i < ans.size(); i++) {
			std::cout << ' ' << ans[i];
		}
		std::cout << '\n';
	}
}