#include <iostream>
#include <algorithm>
#include <cmath>

using ll = long long;

const int maxn = 1e3+2;

long long M[maxn][maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> M[i][j];
		}
	}
	std::cout << int(sqrt(M[1][0] * M[0][2] / M[1][2])+0.5) << ' ';
	for (int i = 1; i < n-1; i++) {
		std::cout << int(sqrt(M[i+1][i] * M[i][i-1] / M[i+1][i-1])+0.5) << ' ';
	}
	std::cout << int(sqrt(M[n-2][n-1] * M[n-1][n-3] / M[n-2][n-3])+0.5) << '\n';
}