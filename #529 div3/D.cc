#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a[2][200000];
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[0][i] >> a[1][i];
	}
	if (n == 3) std::cout << "1 2 3\n", exit(0);
	int now = 1;
	for (int i = 1; i <= n; i++) {
		std::cout << now << " ";
		if (a[1][now] == a[0][a[0][now]] || a[1][now] == a[1][a[0][now]]) {
			now = a[0][now];
		} else {
			now = a[1][now];
		}
	}
}