#include <iostream>

const int maxn = 1e5+7;

int n;
std::pair<int, int> p[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> p[i].first >> p[i].second;
	}
	bool yes = 1;
	if (n % 2 == 1) {
		yes = 0;
	} else {
		for (int i = 0; i < n/2; i++) {
			if (p[i].first-p[i+1].first != p[(i+n/2+1)%n].first-p[i+n/2].first) {
				yes = 0;
				break;
			}
			if (p[i].second-p[i+1].second != p[(i+n/2+1)%n].second-p[i+n/2].second) {
				yes = 0;
				break;
			}
		}
	}
	if (yes) {
		std::cout << "YES\n";
	} else {
		std::cout << "nO\n";
	}
}