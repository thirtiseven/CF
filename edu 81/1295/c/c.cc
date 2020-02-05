#include <iostream>
#include <string>

int T;
std::string s, t;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s >> t;
		int next[s.length()+1][30];
		for (int i = 0; i < 26; i++) {
			next[s.length()][i] = -1;
		}
		for (int i = s.length()-1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				next[i][j] = next[i+1][j];
			}
			next[i][int(s[i]-'a')] = i;
		}
		int nows = 0;
		int ans = 1;
//		for (int i = 0; i <= s.length(); i++) {
//			for (int j = 0; j < 26; j++) {
//				std::cout << next[i][j] << ' ';
//			}
//			std::cout << '\n';
//		}
		for (int i = 0; i < t.length(); i++) {
//			std::cout << nows << ' ' << next[nows][int(t[i]-'a')] << ' ';
			if (next[nows][int(t[i]-'a')] == -1) {
				if (nows == 0) {
					ans = -1;
					break;
				} else {
					ans++;
					nows = 0;
					i--;
				}
			} else {
				nows = next[nows][int(t[i]-'a')]+1;
			}
//			std::cout << nows << '\n';
		}
		std::cout << ans << '\n';
	}
}