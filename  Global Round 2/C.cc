#include <iostream>

const int maxn = 543;

int A[maxn][maxn], B[maxn][maxn], C[maxn][maxn];

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> A[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> B[i][j];
			C[i][j] = A[i][j]^B[i][j];
		}
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x += C[i][j];
		}
		if (x%2!=0) {
			std::cout << "No\n";
			exit(0);
		}
		x = 0;
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			x += C[i][j];
		}
		if (x%2!=0) {
			std::cout << "No\n";
			exit(0);
		}
		x = 0;
	}
	std::cout << "Yes\n";
}