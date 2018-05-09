#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

const int maxn = 2e9+9;
std::set<std::string> aa;
std::vector<int> a;

void dfs(std::string s, int depth) {
//	std::cout << s << '\n';
	if (aa.count(s)) {
//		std::cout << s << "!!!!!\n";
		a.push_back(depth);
	}
	if (s.length() == 1) return;
	for (int i = 0; i < s.length(); i++) {
		std::string t = s;
		t.erase(i, 1);
		if (t[0] != '0') {
			dfs(t, depth+1);
		}
	}
}

int main(int argc, char *argv[]) {  
	for (int i = 1; i*i <= maxn; i++) {
		aa.insert(std::to_string(i*i));
	}
	std::string s, t;
	std::cin >> s;
	int len = s.length();
	dfs(s, 0);
	std::sort(a.begin(), a.end());
	if(a.size()) {
		std::cout << a[0];
	} else {
		std::cout << "-1";
	}
}