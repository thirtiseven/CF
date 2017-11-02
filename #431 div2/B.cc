#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#define maxn 1010
#define inf 100000000

int n, y[maxn];
double k = inf;
double minx, miny = inf;
std::set<int> c;
std::vector<int> d;

bool ok() {
	int j = 0, i;
	for(i = 2; i < n && j >= -1 && j <= 1; i++) {
		if(y[i]-y[i-1]==d[0]) {
			j--;
		} else if(y[i]-y[i-1]==d[2]) {
			j++;
		}
	}
	if(i > n) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> y[i];
		if(i != 1) {
			c.insert(y[i]-y[i-1]);
		}
	}
	bool flag = 0;
	if(c.size() == 2 || c.size() == 3) {
		flag = 1;
	}
	if(c.size() == 3) {
		for(std::set<int>::iterator it = c.begin(); it != c.end(); it++) {
			d.push_back(*it);
		}
		std::sort(d.begin(), d.end());
		if(d[0] + d[2] == 2 * d[1] && ok()) {
			flag = 1;
		} else {
			flag = 0;
		}
	}
	std::cout << (flag?"YES":"NO");
	return 0;
}