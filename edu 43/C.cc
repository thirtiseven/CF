#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <map>

const int maxn = 3e5+7;

struct no {
	int b, e, id;
};

bool cmp(no a, no b) {
	return a.b < b.b;
}

int main(int argc, char *argv[]) {  
	int n;
	no a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].b >> a[i].e;
		a[i].id = i+1;
 	}
	std::sort(a, a+n, cmp);
	for (int i = 1; i < n; i++) {
		if (a[i].e <= a[i-1].e) {
			std::cout << a[i].id << " " << a[i-1].id;
			return 0;
		}
	}
	std::cout << "-1 -1";
}