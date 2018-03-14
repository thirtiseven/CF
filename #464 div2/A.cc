#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	int f[5432];
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> f[i];
	}
	bool yes = 0;
	for (int i = 1; i <= n; i++) {
		if (f[f[f[i]]] == i) {
			yes = 1;
//			std::cout << i << " " << f[i] << " " << f[f[i]] << " " << f[f[f[i]]] << '\n';
			break;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}