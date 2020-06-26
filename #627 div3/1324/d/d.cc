#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int n, a[maxn], b[maxn];

void add(int i, int x) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

}