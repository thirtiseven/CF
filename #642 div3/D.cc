#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int maxn = 2e5+7;
int t, n;
int a[maxn];

struct cmp {
	bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
		if (a.second-a.first == b.second-b.first) {
			return a.first > b.first;
		}
		return a.second-a.first < b.second-b.first;
	}
};

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> q;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		q.push(std::make_pair(1, n));
		int cnt = 1;
		while (!q.empty()) {
			std::pair<int, int> x = q.top();
			q.pop();
			int y = (x.first+x.second+2)/2-1;
			a[y] = cnt;
			cnt++;
			if (x.second > y) {
				q.push(std::make_pair(y+1, x.second));
			}
			if (x.first < y) {
				q.push(std::make_pair(x.first, y-1));
			}
		}
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << " \n"[i==n];
		}
	}
}