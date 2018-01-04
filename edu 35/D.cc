#include <iostream>
#include <vector>

struct point {
	int x, y;
	point(int a, int b) {x = a, y = b;}
};

std::vector<point> v;

int main(int argc, char *argv[]) {  
	int n, m, a[1509];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int cnt = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] > a[j]) {
				v.push_back(point(i, j));
				cnt++;
			}
		}
	}
//	std::cout << cnt << '\n';
	std::cin >> m;
	int l, r;
	for(int i = 0; i < m; i++) {
		std::cin >> l >> r;
		if(((r-l+1)/2) % 2 == 1) {
			cnt++;
		}
		if(cnt%2==1) {
			std::cout << "odd\n";
		} else {
			std::cout << "even\n";
		}
	}
	return 0;
}