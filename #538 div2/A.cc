#include <iostream>

int main(int argc, char *argv[]) {  
	int x, y, z, a, b, c;
	std::cin >> a >> b >> c >> x >> y >> z;
	y += x;
	z += y;
	bool yes = 0;
	x -= a;
	if (x >= 0) {
		y -= a;
		y -= b;
		if (y >= 0) {
			z -= a;
			z -= b;
			z -= c;
			if (z >= 0) {
				yes = 1;
			}
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}