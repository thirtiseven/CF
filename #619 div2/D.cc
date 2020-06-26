#include <iostream>
#include <string>
#include <vector>

int n, m, k;
std::vector<std::pair<int, std::string>> res;

void out() {
	int xx = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].first != 0) {
			xx++;
		}
	}
	if (xx > 3000) {
		int y = 0;
		int x = 10/y;
		exit(1);
	}
	std::cout << xx << '\n';
	for (auto it: res) {
		if (it.first != 0) {
			std::cout << it.first << ' ' << it.second << '\n';
		}
	}
	exit(0);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> m >> k;
	if (k > 4*n*m-2*n-2*m) {
		std::cout << "NO\n";
		exit(0);
	} 
	std::cout << "YES\n";
	int cur = k;
	if (cur > (m-1)*5) {
		cur -= (m-1)*5;
		for (int i = 0; i < m-1; i++) {
			res.push_back(std::make_pair(2, "DR"));
			res.push_back(std::make_pair(3, "ULR"));
//			std::cout << "2 DR\n3 ULR\n";
		}
	} else {
		std::string ans = "";
		for (int i = 0; i < m-1; i++) {
			ans += "DRULR";
		}
		for (int i = 0; i < cur; i++) {
			res.push_back(std::make_pair(1, ans.substr(i, 1)));
//			std::cout << "1 " << ans[i] << '\n';
		}
		out();
	}
//	std::cout << "1 D\n";
	res.push_back(std::make_pair(1, "D"));
	cur--;
	if (cur == 0) {
		out();
	}
	for (int i = 0; i < n-2; i++) {
		if (cur > m-1) {
			res.push_back(std::make_pair(m-1, "L"));
//			std::cout << m-1 << " L\n";
			cur -= (m-1);
		} else {
//			std::cout << cur << " L\n";
			res.push_back(std::make_pair(cur, "L"));
//			cnt++;
			out();
		}
//		std::cout << "1 D\n";
		res.push_back(std::make_pair(1, "D"));
		cur--;
		if (cur == 0) {
			out();
		}
		if (cur > (m-1)*3) {
			cur -= (m-1)*3;
			res.push_back(std::make_pair(m-1, "RUD"));
		} else {
			std::string ans = "";
			for (int j = 0; j < m-1; j++) {
				ans += "RUD";
			}
			for (int i = 0; i < cur; i++) {
				res.push_back(std::make_pair(1, ans.substr(i, 1)));
			}
			out();
		}
	}
	res.push_back(std::make_pair(std::min(m-1, cur), "L"));
	cur -= (m-1);
	if (cur <= 0) {
		out();
	}
	res.push_back(std::make_pair(std::min(n-1, cur), "U"));
	out();
}