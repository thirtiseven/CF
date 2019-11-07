#include <iostream>
#include <algorithm>

using ll = long long;

const int maxn = 1e5+7;

ll a[maxn], n, k;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	ll left = 0, right = n-1, l = 1, r = 1, cur = k;
	while (a[left+1] == a[left]) {
		left++;
		l++;
	}
	while (a[right-1] == a[right]) {
		right--;
		r++;
	}
	while (cur > 0 && left < right) {
//		std::cerr << a[right] - a[left] << "!!!" << left << ' ' << right << ' ' << l << ' ' << r << ' ' << cur << '\n';
//		for (int i = 0; i < n; i++) {
//			std::cerr << a[i] << ' ';
//		}
//		std::cerr << '\n';
		if (l < r) {
			if (cur >= (a[left+1]-a[left])*l) {
				cur -= (a[left+1]-a[left])*l;
				l++;
				left++;
			} else {
				a[left] += cur/l;
				cur = 0;
			}
		} else {
			if (cur >= (a[right]-a[right-1])*r) {
				cur -= (a[right]-a[right-1])*r;
				r++;
				right--;
			} else {
				a[right] -= cur/r;
				cur = 0;
			}
		}
		while (a[left+1] == a[left]) {
			left++;
			l++;
			if (left >= right) {
				goto out;
			}
		}
		while (a[right-1] == a[right]) {
			right--;
			r++;
			if (left >= right) {
				goto out;
			}
		}
		out:;
	}
	std::cout << a[right] - a[left] << '\n';
}