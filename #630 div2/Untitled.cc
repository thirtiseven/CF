#include <iostream>

int t, a, b, c, d, x, y, x1, x2, y1, y2;


int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c >> d;
		std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && (a > 0 || b > 0)) {
			std::cout << "No\n";
			continue;
		}
		if (y1 == y2 && (c > 0 || d > 0)) {
			std::cout << "No\n";
			continue;
		}
		b-=a;
		d-=c;
		x+=b;
		y+=d;
		if (x <= x2 && x >= x1 && y <= y2 && y >= y1) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}