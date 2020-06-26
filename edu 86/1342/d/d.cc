#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

const int maxn = 2e5+7;

struct state{
	int cur, left, id;
	state(int a = 0, int b = 0, int c = 0) {
		cur = a;
		left = b;
		id = c;
	}
};

int n, k, m[maxn], c[maxn], arrow[maxn], num[maxn];
std::deque<state> q;
std::vector<std::vector<int>> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	std::fill(num, num+k, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> m[i];
		num[m[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i];
	}
	c[0] = 100000000;
	for (int i = 1; i <= k; i++) {
		if (c[i-1] > c[i]) {
			arrow[i] = i-1;
		} else {
			arrow[i] = arrow[i-1];
			while (c[arrow[i]] <= c[i]) {
				arrow[i] = arrow[arrow[i]];
			}
		}
	}
//	for (int i = 1; i <= k; i++) {
//		std::cout << arrow[i] << " \n"[i==k];
//	}
	std::sort(m+1, m+n+1);
	q.push_back(state(k, c[k], 0));
	std::vector<int> emp;
	ans.push_back(emp);
	for (int i = n; i >= 1; i--) {
//		std::cout << m[i] << ' ' << q.front().cur << ' ' << q.front().left << ' ' << q.front().id << '\n';
		if (m[i] <= q.front().cur) {
			state temp = q.front();
			q.pop_front();
			if (temp.left > 1) {
				temp.left--;
			} else {
				temp.cur = arrow[temp.cur];
				temp.left = c[temp.cur];
				temp.left -= ans[temp.id].size();
				temp.left--;
			}
			ans[temp.id].push_back(m[i]);
			if (temp.left > 0 && temp.cur > 0) {
//				std::cout << "! " << temp.cur << ' ' << temp.left << ' ' << temp.id << '\n';
				q.push_back(temp);
			}
			if (q.empty() && i > 1) {
//				std::cout << "! " << k << ' ' << c[k] << ' ' << ans.size() << '\n';
				q.push_front(state(k, c[k], ans.size()));
				ans.push_back(emp);
			}
		} else {
//			std::cout << "! " << k << ' ' << c[k] << ' ' << ans.size() << '\n';
			q.push_front(state(k, c[k], ans.size()));
			ans.push_back(emp);
			state temp = q.front();
			q.pop_front();
			if (temp.left > 1) {
				temp.left--;
			} else {
				temp.cur = arrow[temp.cur];
				temp.left = c[temp.cur];
				temp.left -= ans[temp.id].size();
				temp.left--;
			}
			ans[temp.id].push_back(m[i]);
			if (temp.left > 0 && temp.cur > 0) {
//				std::cout << "! " << temp.cur << ' ' << temp.left << ' ' << temp.id << '\n';
				q.push_back(temp);
			}
			if (q.empty() && i > 1) {
//				std::cout << "! " << k << ' ' << c[k] << ' ' << ans.size() << '\n';
				q.push_front(state(k, c[k], ans.size()));
				ans.push_back(emp);
			}
		}
	}
	std::cout << ans.size() << '\n';
	for (auto it: ans) {
		std::cout << it.size();
		for (auto x: it) {
			std::cout << ' ' << x;
		}
		std::cout << '\n';
	}
}