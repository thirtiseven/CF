#include <iostream>
#include <vector>
#include <map>

int n, a, b;
int p[100010];
std::vector <int> v;
std::map <int, int> mp;

int main() {
	std::cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		std::cin >> p[i];
		mp[p[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (mp[a - p[i]] == 0) {
			v.push_back(p[i]);
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		if (mp[b - v[i]] == 0) {
			std::cout << "NO";
			exit(0);
		}
		mp[v[i]] = 2;
		if (mp[b - v[i]] == 1) {
			mp[b - v[i]] = 2;
			if (mp[a - (b - v[i])] == 1) {
				v.push_back(a - (b - v[i]));
			}
		}
	}
	std::cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		std::cout << mp[p[i]] - 1 << " ";
	}
}