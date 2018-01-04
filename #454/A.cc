#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int v1, v2, v3, vm, a1, a2, a3;
	std::cin >> v1 >> v2 >> v3 >> vm;
	a1 = 2 * v1, a2 = 2 * v2, a3 = std::max(v3, vm);
	bool yes = 1;
	if(vm*2 < v3 || vm > 2*v3 || vm>=v2) {
		yes = 0;
	}
	if(yes) {
		std::cout << a1 << '\n' << a2 << '\n' << a3 << '\n';
	} else {
		std::cout << "-1\n";
	}
	return 0;
}