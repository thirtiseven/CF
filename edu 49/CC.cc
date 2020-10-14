#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

const int maxn = 1e4+2;

int cnt[maxn];
std::vector<int> v;
int n, T, x;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		v.clear();
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			cnt[x]++;
			if(cnt[x] >= 2) {
				v.push_back(x);
				cnt[x]=0;
			}
		}
		std::sort(v.begin(), v.end());
		int cur = 0;
		for (int i = 1; i < v.size() - 1; i++) {
			if(v[cur+1]*v[i] > v[cur]*v[i+1]) {
				cur = i;
			}
		}
		std::cout << v[cur] << " " << v[cur] << " " << v[cur+1] << " " << v[cur+1] << '\n';
	}
	return 0;
}