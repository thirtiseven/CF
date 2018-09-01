#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1024;

int avi[maxn];
int p, q, l, r, a, b, c, d;
std::vector<std::pair<int, int>> x;

int main(int argc, char *argv[]) {  
	std::cin >> p >> q >> l >> r;
	std::fill(avi, avi+maxn, 0);
	for (int i = 0; i < p; i++) {
		std::cin >> a >> b;
		for (int i = a; i <= b; i++) {
			avi[i] = 1;
		}
	}
	for (int i = 0; i < q; i++) {
		std::cin >> c >> d;
		x.push_back(std::make_pair(c, d));
	}
	int ans = 0;
	for (int i = l; i <= r; i++) {
		for (auto p: x) {
			for (int j = p.first+i; j <= 1000 && j <= p.second+i; j++) {
				if (avi[j]) {
					ans++;
					goto out;
				}
			}
		}
		out:;
	}
	std::cout << ans << '\n';
}