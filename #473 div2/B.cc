#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	long long n, k, m;
	std::cin >> n >> k >> m;
	std::string s;
	std::map<std::string, long long> mm;
	long long a[maxn];
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		mm[s]=i;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		long long x;
		std::cin >> x;
		std::vector<int> miao;
		long long t;
		long long minn = 1e12;
		for (int j = 0; j < x; j++) {
			std::cin >> t;
			miao.push_back(t);
			minn = std::min(a[t], minn);
		}
		for (int it: miao) {
			a[it] = minn;
//			std::cout << it << " " << minn << '\n';
		}
		miao.clear();
	}
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> s;
		sum += a[mm[s]];
//		std::cout << sum << std::endl; 
	}
	std::cout << sum;
}