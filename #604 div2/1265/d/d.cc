#include <iostream>
#include <vector>

int a, b, c, d;

int main(int argc, char *argv[]) {  
	std::cin >> a >> b >> c >> d;
	if (a + c < b + d - 1 || a + c > b + d + 1) {
		std::cout << "NO\n";
	} else {
		std::vector<int> ans1, ans2;
		int n = a + b + c + d;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (a > 0) {
					ans1.push_back(0);
					a--;
				} else {
					ans1.push_back(2);
				}
			} else {
				if (b > 0) {
					ans1.push_back(1);
					b--;
				} else {
					ans1.push_back(3);
				}
			}			
		}		
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (b > 0) {
					ans2.push_back(1);
					b--;
				} else {
					ans2.push_back(3);
				}
			} else {
				if (a > 0) {
					ans2.push_back(0);
					a--;
				} else {
					ans2.push_back(2);
				}
			}				
		}
		bool yes1 = 1, yes2 = 1;
		if (a + c < b + d) {
			yes1 = 0;
		} else if (a + c > b + d) {
			yes2 = 0;
		}
		for (int i = 1; i < n; i++) {
			if (std::abs(ans1[i]-ans1[i-1]) > 1) {
				yes = 0;
				break;
			}
		}
		for (int i = 1; i < n; i++) {
			if (std::abs(ans2[i]-ans2[i-1]) > 1) {
				yes = 0;
				break;
			}
		}
		if (yes1) {
			std::cout << "YES\n";
			for (int i = 0; i < n; i++) {
				std::cout << ans1[i] << ' ';
			}
			std::cout << '\n';
		} else if (yes2) {
			std::cout << "YES\n";
			for (int i = 0; i < n; i++) {
				std::cout << ans2 [i] << ' ';
			}
			std::cout << '\n';
		} else {
			std::cout << "NO\n";
		}
	}
}