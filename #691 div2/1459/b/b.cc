#include <iostream>
#include <algorithm>

const int maxn = 1024;

int m[maxn][maxn];
int n;

std::pair<int, int> check(int a, int b) {
	int c = std::min(a, b);
	int d = std::max(a, b);
	int res1 = c*2, res2 = c*2;
	if (d-c==0) {
		return std::make_pair(res1, res1);
	}
	if ((d-c)%2==0) {
		res1 += (d-c)*2;
	} else {
		res1 += (d-c)/2*4+1;
	}
	res2 += (d-c)*3;
	return std::make_pair(res1, res2);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	int ans = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			auto x = check(i, j);
			if (i != j && x.first <= n && (n-x.first)%2==0) {
//				std::cerr << i << ' ' << j << '\n';
				ans++;
			}
			if (i == j && x.first <= n && (n - x.first) % 4 == 0) {
				ans++;
			}
		}
	}
	ans *= 4;
	if (n % 4 == 0) {
		ans++;
	}
	std::cout << ans << '\n';
}