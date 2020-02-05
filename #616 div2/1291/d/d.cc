#include <iostream>
#include <string>
#include <cstring>

const int maxn = 2e5+7;

std::string s;
int T;
int l, r, q;
int ocr[maxn][30];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
		std::cin >> s >> q;
		memset(ocr, 0, sizeof(ocr));
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 26; j++) {
				ocr[i+1][j] = ocr[i][j];
			}
			ocr[i+1][int(s[i]-'a')]++;
		}
		while (q--) {
			std::cin >> l >> r;
			int maxx = 0, cnt = 0;
			for (int i = 0; i < 26; i++) {
				maxx = std::max(maxx, ocr[r][i]-ocr[l-1][i]);
				cnt += (ocr[r][i]-ocr[l-1][i]>0);
			}
//			std::cout << maxx << ' ' << (r-l+1)/2 << '\n';
			if (l == r) {
				std::cout << "Yes\n";
			} else if (maxx == (r-l+1)) {
				std::cout << "No\n";
			} else if (s[l-1] == s[r-1] && cnt == 2) {
				std::cout << "No\n";
			} else {
				std::cout << "Yes\n";
			}
		}
}