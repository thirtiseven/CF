#include <iostream>
#include <vector>

const int maxn = 1e5+9;

int main(int argc, char *argv[]) {  
	int n, a, b;
	std::vector<int> t[maxn];
	std::cin >> n;
	for (int i = 0; i < n-1; i++) {
		std::cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	int cnt = 0, dd, oo;
	for (int i = 0; i <= n; i++) {
		if (t[i].size() > 2) {
			cnr++;
			dd = i;
		}
		if (t[i].size() == 1) {
			oo = i;
		}
	}
	if (cnt > 1) {
		std::cout << "NO";
	} else {
		std::cout << "YES\n";
		if (cnt == 0) {
			std::cout << "1\n";
			int next = oo;
			for (int i = 0; i < n-1; i++) {
				std::cout << next << " ";
				next = t[next][0];
			}
			std::cout << next << " ";
		} else {
			std::cout << t[dd].size() << "\n";
			for (int i = 0; i < t[dd].size(); i++) {
				std::cout << dd;
				int next = t[dd][i];
				while(t[next].size() == 1) {
					std::cout << next << " ";
					next = t[next][];
				}
				std::cout << next << " ";
			}
		}
	}
}