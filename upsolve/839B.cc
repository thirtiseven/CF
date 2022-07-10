#include <iostream>
#include <algorithm>
#include <queue>

const int maxn = 1e5+7;

int n, k, a[maxn];
std::priority_queue<int> pq;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> a[i];
		pq.push(a[i]);
	}
	bool yes = 1;
	int two = n*2, four = n, one = 0;
	while (!pq.empty()) {
		int cur = pq.top();
//		std::cerr << cur << " " << one << ' ' << two << ' ' << four << '\n';
		pq.pop();
		if (cur >= 4) {
			int takes_four = cur/4;
			if (takes_four < four) {
				four -= takes_four;
			} else {
				takes_four -= four;
				four = 0;
				int takes_two = takes_four * 2;
				two -= takes_two;
				if (two < 0) {
					yes = 0;
					break;
				}
			}
			if (cur%4) pq.push(cur%4);
		} else {
			if (cur == 3) {
				if (four > 0) {
					four--;
				} else {
					two -= 2;
				}
			} else if (cur == 2) {
				if (two > 0) {
					two --;
				} else if (four > 0) {
					four --;
					one ++;
				} else {
					one -= 2;
				}
			} else if (cur == 1) {
				if (one > 0) {
					one --;
				} else if (two > 0) {
					two --;
				} else if (four > 0) {
					four --;
					two ++;
				} else {
					yes = 0;
					break;
				}
			} else {
				yes = 0;
				break;
			}
		}
//		std::cerr << cur << " " << one << ' ' << two << ' ' << four << '\n';
		if (one < 0 || two < 0 || four < 0) {
			yes = 0;
			break;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}