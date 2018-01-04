#include <iostream>
#include <algorithm>
#include <cstring>

#define maxn 1000010

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	bool yes[maxn];
	memset(yes, 0, sizeof(yes));
	int n, temp;
	std::cin >> n;
	int start = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> temp;
		for(int j = std::max(start, i - temp); j < i; j++) {
			yes[j] = 1;
		}
		if(i - temp < start) {
			start = i;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += yes[i];
		//std::cout << yes[i] << " ";
	}
	std::cout << n-ans << std::endl;
	return 0;
}