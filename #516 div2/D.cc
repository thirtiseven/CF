#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

const int inf = 1e9+7;
const int maxn = 2018;

std::queue<std::pair<int, int>> q;
int left[maxn][maxn], right[maxn][maxn];

int n, m, r, c, x, y;
std::string mp[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	for (int i = 0; i < n; i++) {
		std::cin >> mp[i];
	}
	for (int i = 0; i < maxn; i++) {
		std::fill(left[i], left[i]+maxn, inf);
		std::fill(right[i], right[i]+maxn, inf);
	}
	q.push(std::make_pair(r, c));
	left[r][c] = 0;
	right[r][c] = 0;
	int nx, ny;
	std::pair<int, int> cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		nx = cur.first, ny = cur.second;
		if (nx > 0 && (right[nx-1][ny]>right[nx][ny] || left[nx-1][ny]>left[nx][ny]) && mp[nx-1][ny] == '.') {
			q.push(std::make_pair(nx-1, ny));
			right[nx-1][ny] = std::min(right[nx][ny], right[nx-1][ny]);
			left[nx-1][ny] = std::min(left[nx][ny], left[nx-1][ny]);
		}
		if (nx < n-1 && (right[nx+1][ny]>right[nx][ny] || left[nx+1][ny]>left[nx][ny]) && mp[nx+1][ny] == '.') {
			q.push(std::make_pair(nx+1, ny));
			right[nx+1][ny] = std::min(right[nx][ny], right[nx+1][ny]);
			left[nx+1][ny] = std::min(left[nx][ny], left[nx+1][ny]);
		}
		if (ny > 0 && (right[nx][ny-1]>right[nx][ny] || left[nx][ny-1]>left[nx][ny]) && mp[nx][ny-1] == '.') {
			q.push(std::make_pair(nx, ny-1));
			right[nx][ny-1] = std::min(right[nx][ny], right[nx][ny-1]);
			left[nx][ny-1] = std::min(left[nx][ny]+1, left[nx][ny-1]);
		}
		if (ny < m-1 && (right[nx][ny+1]>right[nx][ny] || left[nx][ny+1]>left[nx][ny]) && mp[nx][ny+1] == '.') {
			q.push(std::make_pair(nx, ny+1));
			right[nx][ny+1] = std::min(right[nx][ny]+1, right[nx][ny+1]);
			left[nx][ny+1] = std::min(left[nx][ny], left[nx][ny+1]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (left[i][j] <= x && right[i][j] <= y) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}