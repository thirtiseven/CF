#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n, t, maxx = -10, minn = 1000000010;
	std::multiset<int> a;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> t;
		a.insert(t);
		minn = std::min(minn, t);
		maxx = std::max(maxx, t);
	}
	int ans = a.size() - a.count(minn) - a.count(maxx);
	if(ans < 0) {
		ans = 0;
	}
	//std::cout << maxx << " " << minn << "\n";
	std::cout << ans;
	return 0;
}