#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	bool paper[105][105];
	int n, m;
	std::cin >> n >> m;
	int numb = 0;
	int mini = 110, minj = 110, maxi = -1, maxj = -1;
	char temp;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> temp;
			if(temp == 'B') {
				paper[i][j] = 1;
				numb++;
				mini = std::min(mini, i);
				minj = std::min(minj, j);
				maxi = std::max(maxi, i);
				maxj = std::max(maxj, j);
			} else {
				paper[i][j] = 0;
			}
		}
	}
	int square = std::max(maxj - minj + 1, maxi - mini + 1);
	int ans;
	if(square == -110) {
		ans = 1;
	} else if(square > m || square > n) {
		ans = -1;
	} else {
		ans = square * square - numb;
	}
	std::cout << ans << std::endl;
	return 0;
}