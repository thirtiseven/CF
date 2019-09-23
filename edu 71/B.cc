#include <iostream>
#include <vector>

int A[52][52];
int B[52][52];

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> A[i][j];
			B[i][j] = 0;
		}
	}
	
	bool yes = 1;
	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			if (A[i][j] == A[i+1][j] && A[i][j] == A[i][j+1] && A[i][j] == A[i+1][j+1] && A[i][j] == 1) {
				B[i][j] = B[i+1][j] = B[i][j+1] = B[i+1][j+1] = 1;
				ans.push_back(std::make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				yes = 0;
			}
		}
	}
	if (yes) {
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it.first+1 << " " << it.second+1 << '\n';
		}
	} else {
		std::cout << "-1\n";
	}
}