#include <iostream>
#include <string>
#include <set>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	std::set<char> num[11];
	std::set<std::string> aa;
	std::string ss[2009];
	for (int CAS = 1; CAS <= T; CAS++) {
		for (int i = 0; i < 11; i++) {
			num[i].clear();
		}
		aa.clear();
		int n, l;
		std::cin >> n >> l;
		for (int i = 0; i < n; i++) {
			std::cin >> ss[i];
			aa.insert(ss[i]);
			for (int j = 0; j < l; j++) {
				num[j].insert(ss[i][j]);
			}
		}
		int tot = 1;
		for (int i = 0; i < l; i++) {
			tot *= num[i].size();
		}
		if (tot == n) {
			std::cout << "Case #" << CAS << ": -\n";
			continue;
		}
		std::string ans;
		for (int i = 0; i < n-1; i++) {
			ans = ss[i];
			for (int j = 0; j < l; j++) {
				for (int k = 0; k < n; k++) {
					ans[j] = ss[k][j];
					if (aa.count(ans) == 0) {
						std::cout << "Case #" << CAS << ": " << ans << "\n";
						goto outside;
					}
				} 
			}
		}
		outside:;
	}
}