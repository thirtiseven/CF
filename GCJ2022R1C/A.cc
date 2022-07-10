#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

const int maxn = 103;
const std::string imp = "IMPOSSIBLE";

int T, n;
std::string s[maxn];
std::map<char, std::string> mp;
std::set<char> startwith, endwith;

bool all_same(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[0]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n;
		mp.clear();
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
			if (all_same(s[i])) {
				mp[s[i][0]] += s[i];
				s[i] = "";
			}
		}
		std::string ans = "";
		char head = '?';
		while (mp.size() > 0) {
			for (auto it: mp) {
				startwith.insert(it.first);
				endwith.insert(it.second[it.second.length()-1]);
			}
			head = '?';
			for (char i = 'A'; i <= 'Z'; i++) {
				if (startwith.count(i) > 0 && endwith.count(i) == 0) {
					head = i;
					break;
				}
			}
			if (head == '?') {
				break;
			}
			for (int i = 0; i < n; i++) {
				if (s[i] != "") {
					mp[s[i][0]] += s[i];
				}
			}
			while (mp.find(head) != mp.end()) {
				ans += mp[head];
				mp.erase(head);
				startwith.erase(head);
				endwith.erase(ans[ans.length()-1]);
				head = ans[ans.length()-1];
			}
		}
		if (mp.size() > 0) {
			std::cout << imp << '\n';
		}
		std::cout << ans << '\n';
	}
}