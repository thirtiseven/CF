#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

int T;
int n;
int a[maxn], x;
std::vector<std::pair<int, int>> q;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int _ = 1; _ <= T; _++) {
		q.clear();
		std::cin >> n >> x;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			q.push_back(std::make_pair((a[i]-1)/x+1, i+1));
		}
		std::sort(q.begin(), q.end());
		std::cout << "Case #" << _ << ": ";
		for (auto it: q) {
			std::cout << it.second << ' ';
		}
		std::cout << '\n';
	}
}