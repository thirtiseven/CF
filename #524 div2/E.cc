#include <iostream>
#include <set>

const int maxn = 250;

std::multiset<std::pair<int, int>> ms;
std::string st[maxn];
int cha[30];

bool check() {
	int cnt = 0;
	for (auto it: cha) {
		if (it&1) cnt++;
	}
	if (cnt>1) return false;
	return true;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> st[i];
		std::fill(cha, cha+30, 0);
		for (int j = 0; j < m; cha[j]--, j++) {
			for (int k = j; k < m; cha[k]++, k++) {
				if (check()) {
					ms.insert(std::make_pair(i, j));
				}
			}
		}
	}
}