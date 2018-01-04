#include <iostream>
#include <string>

int n, m;
std::string s[55], ss;
int odd[110], len;
int si, sj, ei, ej;

int dfs(int a, int b, int c, int d) {
	int nowi = si, nowj = sj;
	for(int i = 0; i < len; i++) {
		if(odd[i] == 0) {
			if(a == 0) {
				nowi++;
			} else if(a == 1) {
				nowj--;
			} else if(a == 2) {
				nowi--;
			} else if(a == 3) {
				nowj++;
			}
		} else if(odd[i] == 1) {
			if(b == 0) {
				nowi++;
			} else if(b == 1) {
				nowj--;
			} else if(b == 2) {
				nowi--;
			} else if(b == 3) {
				nowj++;
			}
		} else if(odd[i] == 2) {
			if(c == 0) {
				nowi++;
			} else if(c == 1) {
				nowj--;
			} else if(c == 2) {
				nowi--;
			} else if(c == 3) {
				nowj++;
			}
		} else if(odd[i] == 3) {
			if(d == 0) {
				nowi++;
			} else if(d == 1) {
				nowj--;
			} else if(d == 2) {
				nowi--;
			} else if(d == 3) {
				nowj++;
			}
		}
//		std::cout << nowi << " " << nowj << " " << i << '\n';
		if(nowi < 0 || nowi >= n || nowj < 0 || nowj >= m) {
//			std::cout << "HELL!\n";
			return 0;
		}
		if(s[nowi][nowj] == '#') {
//			std::cout << "WALL!\n";
			return 0;
		}
		if(s[nowi][nowj] == 'E') {
			return 1;
		}
	}
//	std::cout << "NOTE!\n";
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
		for(int j = 0; j < m; j++) {
			if(s[i][j] == 'S') {
				si = i, sj = j;
			}
			if(s[i][j] == 'E') {
				ei = i, ej = j;
			}
		}
	}
	std::cin >> ss;
	for(int i = 0; i < ss.length(); i++) {
		odd[i] = int(ss[i]-'0');
	}
	len = ss.length();
	int cnt = 0;
	for(int a1 = 0; a1 < 4; a1++) {
		for(int a2 = 0; a2 < 4; a2++) {
			for(int a3 = 0; a3 < 4; a3++) {
				for(int a4 = 0; a4 < 4; a4++) {
					if(a1 != a2 && a1 != a3 && a1 != a4 && a2 != a3 && a2 != a4 && a3 != a4) {
//						std::cout << a1 << " " << a2 << " " << a3 << " " << a4 << '\n';
						cnt += dfs(a1, a2, a3, a4);
					}
				}
			}
		}
	}
	std::cout << cnt;
	return 0;
}