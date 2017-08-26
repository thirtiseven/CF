#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 200010

struct num {
	ll porn;
	ll val;
	ll id;
}a[maxn];

ll n, k, x;
ll neg = 0;

bool cmp_val(num a, num b) {
	return a.val < b.val;
}

bool cmp_id(num a, num b) {
	return a.id < b.id;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> k >> x;
	for(ll i = 0; i < n; i++) {
		std::cin >> a[i].val;
		if(a[i].val < 0) {
			a[i].porn = -1;
			a[i].val = 0 - a[i].val;
			neg++;
		} else {
			a[i].porn = 1;
		}
		a[i].id = i;
	}
	std::sort(a, a+n, cmp_val);
	std::cout << a[0].porn * a[0].val << std::endl;
	if(neg % 2 == 0) {
		while(a[0].val >= 0) {
			k--;
			a[0].val -= x;
			if(k == 0) {
				break;
			}
		}
		if(a[0].val < 0) {
			neg++;
			a[0].val = 0 - a[0].val;
			a[0].porn = 0 - a[0].porn;
		}
	}
	/*
	std::sort(a, a+n, cmp_id);
	for(int i = 0; i < n-1; i++) {
		std::cout << a[i].porn * a[i].val << " ";
	}
	std::cout << a[n-1].porn * a[n-1].val << "\n";
	*/
	std::cout << a[0].porn * a[0].val << std::endl;
	std::sort(a, a+n, cmp_val);
	std::cout << a[0].porn * a[0].val << std::endl;
	if(neg % 2 == 1) {
		if(a[0].porn == 1) {
			a[0].val += k*x;
		} else {
			a[0].val -= k*x;
		}
	}
	std::cout << a[0].porn * a[0].val << std::endl;
	std::sort(a, a+n, cmp_id);
	for(ll i = 0; i < n-1; i++) {
		std::cout << a[i].porn * a[i].val << " ";
	}
	std::cout << a[n-1].porn * a[n-1].val << "\n";
	return 0;
}