#include <iostream>
#include <cstring>

int n, m;
int actor[1010][1010];
int left[1010][1010], right[1010][1010], up[1010][1010], down[1010][1010];

int main(int argc, char *argv[]) { 
	/* 
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof( down));
	*/
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; i++) {
		  	std::cin >> actor[i][j];
			for(int h = 0; h < j; h++) {
				right[i][h] = 1;
			}
			for(int h = 0; h < i; h++) {
				down[h][j] = 1;
			}
			for(int h = i; h < n; h++) {
				up[h][j] = 1;
			}
			for(int h = j; h < m; h++) {
				down[i][h] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; i++) {
			if(!actor[i][j]) {
				if(right[i][j]) {
					ans++;
				}
				if(left[i][j]) {
					ans++;
				}
				if(up[i][j]) {
					ans++;
				}
				if(down[i][j]) {
					ans++;
				}
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}