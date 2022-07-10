#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using ll = long long;

const int maxn = 104;

int T;
int N, A[maxn], B[maxn];

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> N;
		ll cur = 1;
		ll ones = 0;
		ll sum = 0;
		ll max_tar = 0;
		ll mex = 3;
		std::set<int> power;
		std::vector<ll> ans, xx;
		xx.clear();
		ans.clear();
		for (int i = 0; i < N; i++) {
			if (cur <= 1000000000) {
				A[i] = cur;
				power.insert(cur);
				max_tar += A[i];
				cur *= 2;
			} else {
				while (power.count(mex) >= 1) {
					mex++;
				}
				A[i] = mex;
				xx.push_back(A[i]);
				mex++;
			}
			sum += A[i];
		}
		cur /= 2;
		for (int i = 0; i < N; i++) {
			std::cout << A[i] << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < N; i++) {
			std::cin >> B[i];
			sum += B[i];
		}
		ll target = sum / 2;
		for (int i = 0; i < N; i++) {
			xx.push_back(B[i]);
		}
		std::sort(xx.begin(), xx.end());
//		std::cout << "---------------------------------------\n";
//		for (auto it: xx) {
//			std::cout << it << " ";
//		}
//		std::cout << "---------------------------------------\n";
		ll now = 0;
		for (auto it: xx) {
			if (target - now <= max_tar) {
				ll new_tar = target - now;
				while (cur) {
					if (new_tar > cur) {
						new_tar -= cur;
						ans.push_back(cur);
					}
					cur /= 2;
				}
			} else {
				ans.push_back(it);
				now += it;
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			std::cout << ans[i] << " ";
		}
		std::cout << std::endl;
	}
}