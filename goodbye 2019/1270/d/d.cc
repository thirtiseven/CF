#include <iostream>
#include <map>

std::map<int, int> num;

int main(int argc, char *argv[]) {  
	int n, k, pos, a;
	std::cin >> n >> k;
	for (int i = 1; i <= k+1; i++) {
		std::cout << "? ";
		for (int j = 1; j <= k+1; j++) {
			if (j != i) {
				std::cout << j << ' ';
			}
		}
		std::cout << std::endl;
		std::cin >> pos >> a;
		num[a]++;
	}
	int ans = 0;
	for (auto it: num) {
		ans = it.second;
	}
	std::cout << "! " << ans << std::endl;
}