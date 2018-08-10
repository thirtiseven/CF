//author: thirtiseven
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <bitset>

#define pb push_back
#define rep(i,n) for(int i=0; i<n; ++i)
#define mp std::make_pair

const int maxn = 1e5+7;
const int inf = 0x7f7f7f7f;
const int mod = 1e9+7;
const double pi = acos(-1.0);

std::multiset<int> ss, sr;

int n, x, a[maxn];
void inti() {
	std::cin >> n >> x;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		ss.insert(a[i]);
		sr.insert(a[i]&x);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);  
	inti();
	for (auto it: ss) {
		if (ss.count(it) >= 2) {
			std::cout << "0\n";
			exit(0);
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == (a[i]&x) && sr.count(a[i]) >= 2) {
			std::cout << "1\n";
			exit(0);
		} else if (a[i] != (a[i]&x) && sr.count(a[i]) >= 1) {
			std::cout << "1\n";
			exit(0);
		}
	}
	for (auto it: sr) {
		if (sr.count(it) >= 2) {
			std::cout << "2\n";
			exit(0);
		}
	}
	std::cout << "-1\n";
	exit(0);
//	int ans = -1;
//	for (int i = 0; i < n; i++) {
//		if (ss.count(a[i]) > 1) {
//			ans = 0;
//			std::cout << "0\n";
//			exit(0);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (ss.count(a[i]&x) > 0 && (a[i]&x) != a[i]) {
//			ans = 1;
//			std::cout << "1\n";
//			exit(0);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if ((a[i] & x) != a[i]) {
//			ss.insert(a[i]&x);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (ss.count(a[i]&x) > 2 && (a[i]&x) != a[i]) {
//			ans = 1;
//			std::cout << "2\n";
//			exit(0);
//		}
//	}
//	std::cout << "-1\n";
	return 0;
}