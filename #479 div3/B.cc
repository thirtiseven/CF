#include <iostream>
#include <string>
#include <set>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::multiset<std::string> ss;
	std::cin >> n >> s;
	for (int i = 0; i < n-1; i++) {
		ss.insert(s.substr(i, 2));
	}
	int maxx = 0;
	std::string ans;
	for (auto a: ss) {
		if (ss.count(a) > maxx) {
			maxx = ss.count(a);
			ans = a;
		}
	}
	std::cout << ans;
}