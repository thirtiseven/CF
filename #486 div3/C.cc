#include <iostream>
#include <algorithm>
#include <map>

std::map<int, std::pair<int,int>> mp;

int a[200010];
int main(int argc, char *argv[]) {
	int K, n;
	std::cin >> K;
	for (int k = 1; k<=K; k++) {
		std::cin >> n;
		int sum=0;
		for(int i=1; i<=n; i++){
			std::cin >> a[i];
			sum += a[i];
		}
		for (int i=1; i<=n; i++) {
			if (mp.find(sum-a[i])!=mp.end()) {
				std::cout << "YES" << std::endl;
				std::cout << mp[sum-a[i]].first << ' ' << mp[sum-a[i]].second << std::endl;
				std::cout << k << ' ' << i << std::endl;
				exit(0);
			}
		}
		for (int i=1; i<=n; i++) {
			mp[sum-a[i]] = std::make_pair(k,i);
		}
	}
	std::cout << "NO";
}