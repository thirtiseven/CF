#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int t, x;
int n, q, a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> q;
	int num0 = 0, num1 = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i]) {
			num1++;
		} else {
			num0++;
		}
	}
	for (int i = 0; i < q; i++) {
		std::cin >> t >> x;
		if (t == 1) {
			if (a[x-1] == 1) {
				a[x-1] = 0;
				num1--;
				num0++;
			} else {
				a[x-1] = 1;
				num0--;
				num1++;
			}
		} else {
			if (x <= num1) {
				std::cout << "1\n";
			} else {
				std::cout << "0\n";
			}
		}
	}
}