#include <iostream>
#include <set>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, t;
	std::set<int> a;
	std::multiset<int> aa;
	std::cin >> n; 
	for(int i = 0; i < n; i++) {
		std::cin >> t;
		a.insert(t);
		aa.insert(t);
	}
	int ans = 1;
	for(auto it: a) {
		ans = std::max((int)aa.count(it), ans);
	}
	std::cout << ans << std::endl;
	return 0;
}