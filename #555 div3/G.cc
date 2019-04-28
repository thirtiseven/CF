#include <iostream>
#include <bitset>

const int maxn = 207;

int n, m;
int map[maxn][maxn];

int ans1[maxn], ans2[maxn];

bool pure(int r, int should_be) {
	bool yes = 1;
	int val = map[r][0] ^ ans2[0];
	for (int i = 1; i < m; i++) {
		if ((map[r][i] ^ ans2[i]) != val) {
			yes = 0;
			break;
		}
	}
	if (yes == 1 && val != should_be) {
		ans1[r] = 1;
	}
	return yes;
}

bool sorted(int r) {
	bool yes = 1;
 	int val = map[r][0] ^ ans2[0];
	bool firstapp = 1;
	for (int i = 1; i < m; i++) {
		if ((map[r][i] ^ ans2[i]) != val) {
			if (firstapp) {
				firstapp = 0;
				val ^= 1;
			} else {
				yes = 0;
				break;
			}
		}
	}
	if (yes == 1 && (map[r][0] ^ ans2[0]) == 1) {
		ans1[r] = 1;
	}
	return yes;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
		}
	}
	for (int k = 0; k < m; k++) {
		bool yes = 1, oneapp = 0;
		std::fill(ans1, ans1+maxn, 0);
		std::fill(ans2, ans2+maxn, 0);
		for (int i = 0; i < m; i++) {
			if ((i <= k && map[0][i] == 1) || (i > k && map[0][i] == 0)) {
				ans2[i] = 1;
			} 
		}
		if (k == m-1) {
			oneapp = 0;
		}
		for (int i = 0; i < n; i++) {
			if (pure(i, int(oneapp))) {
				continue;
			} else if (!oneapp && sorted(i)) {
				oneapp = 1;
				continue;
			} else {
				oneapp = 1;
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "YES\n";
			for (int i = 0; i < n; i++) {
				std::cout << ans1[i];
			}
			std::cout << '\n';
			for (int i = 0; i < m; i++) {
				std::cout << ans2[i];
			}
			std::cout << '\n';
			exit(0);
		}
	}
	std::cout << "NO\n";
}