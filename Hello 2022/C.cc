#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e4+7;

int t, n, p[maxn], q[maxn];

int x;

std::vector<int> buf, pos;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		int cnt = 0;
		buf.clear();
		std::fill(p, p+n+1, 0);
		
//		std::cout << "? " << 1 << std::endl;
//		std::cin >> x;
//		cnt++;
		
		for (int i = 1; i <= n;) {
			if (p[i] != 0) {
				i++;
				continue;
			}
			std::cout << "? " << i << std::endl;
			std::cin >> x;
			cnt++;
			if (buf.size() > 0 && x == buf[0]) {
				std::cerr << "--------\n";
				for (auto it: buf) {
					std::cerr << it << ' ';
				}
				std::cerr << "\n--------\n";
				pos.clear();
				for (auto it: buf) {
					pos.push_back(it);
				}
				std::sort(pos.begin(), pos.end());
				int c = buf.size();
				for (int i = 0; i < c; i++) {
					p[pos[i]] = buf[(c+2-((cnt+c+i)%c))%c];
				}
				i++;
				buf.clear();
			} else {
				buf.push_back(x);
			}
		}
		std::cout << "!";
		for (int i = 1; i <= n; i++) {
			std::cout << " " << p[i];
		}
		std::cout << std::endl;
	}
}