#include <iostream>
#include <string>
#include <set>

std::set<int> pos;
std::multiset<int> ms;

int main(int argc, char *argv[]) {  
	std::string s;
	int n;
	std::cin >> n;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		tot = 0;
		bool lab = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '(') {
				tot++;
			} else {
				tot--;
			}
			if (tot < 0) {
				lab = 1;
			}
		}
		if (!lab) {
			pos.insert(tot);
			ms.insert(tot);
//			std::cout << tot << '\n';
		} else {
			lab = 0;
			tot = 0;
			for (int j = s.length()-1; j >= 0; j--) {
				if (s[j] == ')') {
					tot++;
				} else {
					tot--;
				}
				if (tot < 0) {
					lab = 1;
				}
			}
			if (!lab) {
				ms.insert(-tot);
//				std::cout << -tot << '\n';
			}
		}
	}
	int ans = 0;
	for (auto it: pos) {
		if (it!=0) ans += std::min(ms.count(it), ms.count(-it));
	}
	ans += ms.count(0)/2;
	std::cout << ans << '\n';
}