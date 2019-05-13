#include <iostream>
#include <string>
#include <set>
#include <algorithm>

const int maxn = 503;

std::string opp[256];

unsigned toint(char a) {
	if (a == 'R') {
		return 0;
	} else if (a == 'S') {
		return 1;
	} 
	return 2;
}

int trie[maxn][3][3];
int xx[3];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		int n;
		std::cin >> n;
		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					trie[i][j][k] = 0;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			xx[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			std::cin >> opp[i];
			xx[toint(opp[i][0])] = 1;
			int len = opp[i].length();
			for (int j = 0; j < maxn-1; j++) {
				trie[j][toint(opp[i][j%len])][toint(opp[i][(j+1)%len])] = 1;
			}
		}
		std::string ans = "";
		bool yes = 1;
		if (xx[0] == 1 && xx[1] == 1 && xx[2] == 1) {
			yes = 0;
		} else if (xx[0] == 1 && xx[1] == 0 && xx[2] == 0) {
			ans += 'P';
		} else if (xx[0] == 0 && xx[1] == 1 && xx[2] == 0) {
			ans += 'R';
		} else if (xx[0] == 0 && xx[1] == 0 && xx[2] == 1) {
			ans += 'S';
		} else {
			int now = 3;
			if (xx[0] == 1 && xx[1] == 1 && xx[2] == 0) {
				ans += 'R';
				now = 0;
			} else if (xx[0] == 1 && xx[1] == 0 && xx[2] == 1) {
				ans += 'P';
				now = 2;
			} else if (xx[0] == 0 && xx[1] == 1 && xx[2] == 1) {
				ans += 'S';
				now = 1;
			} 
			for (int i = 0; i < 500; i++) {
				if (trie[i][now][0] == 1 && trie[i][now][1] == 1 && trie[i][now][2] == 1) {
					yes = 0;
					break;
				} else if (trie[i][now][0] == 1 && trie[i][now][1] == 0 && trie[i][now][2] == 0) {
					ans += 'P';
					break;
				} else if (trie[i][now][0] == 0 && trie[i][now][1] == 1 && trie[i][now][2] == 0) {
					ans += 'R';
					break;
				} else if (trie[i][now][0] == 0 && trie[i][now][1] == 0 && trie[i][now][2] == 1) {
					ans += 'S';
					break;
				} else if (trie[i][now][0] == 1 && trie[i][now][1] == 1 && trie[i][now][2] == 0) {
					ans += 'R';
					now = 0;
				} else if (trie[i][now][0] == 1 && trie[i][now][1] == 0 && trie[i][now][2] == 1) {
					ans += 'P';
					now = 2;
				} else if (trie[i][now][0] == 0 && trie[i][now][1] == 1 && trie[i][now][2] == 1) {
					ans += 'S';
					now = 1;
				}
			}
		}
		if (!yes) {
			std::cout << "Case #" << CAS << ": IMPOSSIBLE\n";
		} else {
			std::cout << "Case #" << CAS << ": " << ans << '\n';
		}
	}
}