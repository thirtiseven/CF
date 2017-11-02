#include <iostream>
#include <string>
#include <algorithm>
#include <set>

int main(int argc, char *argv[]) {  
	std::string s;
	std::set<char> a;
	int n;
	std::cin >> n >> s;
	int ans = -1, begin = 0, end = 0, now = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] <= 'Z' && s[i] >= 'A') {
			ans = std::max(ans, (int)a.size());
			a.clear();
		} else {
			a.insert(s[i]);
			ans = std::max(ans, (int)a.size());
		}			
	}
	std::cout << ans << std::endl;
	return 0;
}