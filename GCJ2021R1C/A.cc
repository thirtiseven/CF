#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

const int maxn = 32;

int T, n, k, p[maxn];

std::vector<int> diff, candidate;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		diff.clear();
		std::cin >> n >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> p[i];
		}
		std::sort(p, p+n);
		for (int i = 1; i < n; i++) {
			diff.emplace_back(std::max(p[i] - p[i-1] - 1, 0));
		}
		std::sort(diff.begin(), diff.end());
		int max_take = 0;
		if(diff.size() >= 1) {
			max_take = diff[diff.size()-1];
		}
//		std::cout << max_take << '\n';
		candidate.clear();
		candidate.emplace_back(p[0]-1);
		candidate.emplace_back(k-p[n-1]);
		if(diff.size() >= 1) candidate.emplace_back((diff[diff.size()-1]+1)/2);
		if(diff.size() >= 2) candidate.emplace_back((diff[diff.size()-2]+1)/2);
		std::sort(candidate.begin(), candidate.end());
		max_take = std::max(max_take, candidate[candidate.size()-1] + candidate[candidate.size()-2]);
		std::cout << "Case #" << CAS << ": " << std::fixed << std::setprecision(10) << double(max_take)/double(k) << '\n';
	}
} 