#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {  
	bool yes[1009];
	memset(yes, 0, sizeof(yes));
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < 2*m; i++) {
		int temp;
		std::cin >> temp;
		yes[temp] = 1;
	}
	int ans;
	for(int i = 1; i <= n; i++) {
		if(!yes[i]) {
			ans = i;
			break;
		}
	}
	std::cout << n-1 << '\n';
	for(int i = 1; i <= n; i++) {
		if(i != ans) {
			std::cout << ans << " " << i << '\n';
		}
	}
	return 0;
}