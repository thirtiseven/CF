#include <iostream>

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	int a[110], s[110], v[110];
	s[0] = 0;
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	int l, r;
	int sum = 0;
	for(int i = 0; i < m; i++) {
		std::cin >> l >> r;
		v[i] = s[r] - s[l-1];
		if(v[i] > 0) {
			sum += v[i];
		}
	}
	std::cout << sum << std::endl;
	return 0;
}