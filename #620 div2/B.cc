#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

std::string a[103];
std::multiset<std::string> s;
std::vector<std::string> ans;
std::string center = "";

std::string b;
int n, m;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		s.insert(a[i]);
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		b = a[i];
		std::reverse(b.begin(), b.end());
		if (a[i] == b) {
			if (s.count(b) != 2) {
				if (b.length() > center.length()) {
					center = b;
				}
			} else if (s.count(b) >= 2) {
				ans.push_back(a[i]);
				len += a[i].length();
			}
			s.erase(a[i]);
		} else {
//			std::cout << a[i] << ' ' << b << ' ';
			if (s.count(b) >= 1) {
//				std::cout << std::min(s.count(a[i]), s.count(b)) << ' ';
//				std::cout << "YES\n";
				for (int j = 0; j < std::min(s.count(a[i]), s.count(b)); j++) {
					ans.push_back(a[i]);
					len += a[i].length();
				}
				s.erase(b);
				s.erase(a[i]);
			}
		}
	}
	std::cout << len*2+center.length() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i];
	}
	std::cout << center;
	for (int i = ans.size()-1; i >= 0; i--) {
		std::reverse(ans[i].begin(), ans[i].end());
		std::cout << ans[i];
	}
	std::cout << '\n';
}