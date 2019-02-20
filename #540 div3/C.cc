#include <iostream>
#include <algorithm>

const int maxn = 1234;
int num[maxn];
int ans[22][22];

int main(int argc, char *argv[]) {  
	std::fill(num, num+maxn, 0);
	int n;
	std::cin >> n;
	int x;
	if (n==1) {
		std::cin >> x;
		std::cout << "YES\n" << x << '\n';
		exit(0);
	}
	for (int i = 0; i < n*n; i++) {
		std::cin >> x;
		num[x]++;
	}
	if (n%2==0) {
		for (int i = 1; i <= 1000; i++) {
			if (num[i]%4!=0) {
				std::cout << "NO\n";
				exit(0);
			}
		}
		int nowx = 0, nowy = 0;
		for (int i = 1; i <= 1000; i++) {
			while (num[i] > 0) {
				ans[nowx][nowy] = ans[n-1-nowx][nowy] = ans[n-1-nowx][n-1-nowy] = ans[nowx][n-1-nowy] = i;
				nowy++;
				if (nowy >= n/2) {
					nowx++;
					nowy = 0;
				}
				num[i] -= 4;
			}
		}
		std::cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << ans[i][j] << " ";
			}
			std::cout << "\n";
		}
	} else {
		int one = 0, two = 0;
		for (int i = 1; i <= 1000; i++) {
			if (num[i]%4!=0) {
				if (one > 1 || two > n-1) {
					std::cout << "NO\n";
					exit(0);
				} else if (num[i]%4 == 1) {
					one++;
				} else if (num[i]%4 == 2) {
					two++;
				} else if (num[i]%4 == 3) {
					one++;
					two++;
				}
			}
		}
		if (one > 1 || two > n-1) {
			std::cout << "NO\n";
			exit(0);
		}
		int nowx = 0, nowy = 0;
		int mid = 0;
		for (int i = 1; i <= 1000; i++) {
			while (num[i] >= 4) {
				if (nowx >= n/2) {
					break;
				}
				ans[nowx][nowy] = ans[n-1-nowx][nowy] = ans[n-1-nowx][n-1-nowy] = ans[nowx][n-1-nowy] = i;
				nowy++;
				if (nowy >= n/2) {
					nowx++;
					nowy = 0;
				}
				num[i] -= 4;
			}	
			while (num[i] >= 2) {
				if (mid < n/2) {
					ans[mid][n/2] = ans[n-1-mid][n/2] = i;
					mid++;
					if (mid == n/2) mid++;
				} else {
					ans[n/2][mid] = ans[n/2][n-1-mid] = i;
					mid++;
				}
				num[i] -= 2;
			}
			if (num[i] == 1) {
				ans[n/2][n/2] = i;
			}
		}
		std::cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << ans[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}