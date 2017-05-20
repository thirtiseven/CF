#include <iostream>
#include <cstring>
#include <algorithm>

#define ll long long
#define inf 1000000000

ll n, m, k, x, y;
ll sergei = 0, cnt_max = 0, cnt_min = 0;

ll cnt_class[110][110];

int main(int argc, char *argv[]) {  
	memset(cnt_class, 0, sizeof(cnt_class));
	std::cin >> n >> m >> k >> x >> y;
	ll div;
	int temp_min = inf, temp_max = -1;
	if(n == 1) {
		div = 2 ;
		ll left = k % m;
		ll cnt_one = k / m;
		for(int i = 0; i < left; i++) {
			cnt_class[0][i]++; 
		}
		sergei = cnt_class[0][y-1];
		cnt_max = cnt_class[0][0];
		cnt_min = cnt_class[0][m-1];
		std::cout << cnt_max + cnt_one << " " << cnt_min + cnt_one  << " " << sergei + cnt_one << std::endl;
		return 0;
	}
	memset(cnt_class, 0, sizeof(cnt_class));
	sergei = 0, cnt_max = 0, cnt_min = 0;
	div = 2 * (n - 1);
	ll basic_add = (k / (m * div));

	if(x == 1 || x == n) {
		sergei += basic_add;
	} else {
		sergei += 2 * basic_add;
	}
	if(n == 2) {
		cnt_max += basic_add;
	} else {
		cnt_max += 2 * basic_add;
	}
	cnt_min += basic_add;

	k %= (div * m);
	
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == 0 || i == n-1) {
				cnt_class[i][j] = basic_add;
			} else {
				cnt_class[i][j] = basic_add * 2;
			}
		}
	}
	*/
	
	//std::cout << div << " " << k << " " << basic_add << " " << (2 * n * m) << std::endl;
	
	for(int i = 0; i < n; i++) {
			if(k < 0) {
				break;
			} else if(k < m) {
				for(int j = 0; j < k; j++) {
					cnt_class[i][j]++;
				}
			} else {
				for(int j = 0; j < m; j++) {
					cnt_class[i][j]++;
				}
			}
			k -= m;
			//std::cout << i << " ";
	}
	for(int i = n - 2; i > 0; i--) {
			if(k < 0) {
				break;
			} else if(k < m) {
				for(int j = 0; j < k; j++) {
					cnt_class[i][j]++;
				}
			} else {
				for(int j = 0; j < m; j++) {
					cnt_class[i][j]++;
				}
			}
			k -= m;
			//std::cout << i << " ";
	}
	
	temp_min = inf;
	temp_max = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(cnt_class[i][j] < temp_min) {
				temp_min = cnt_class[i][j];
			}
			if(cnt_class[i][j] > temp_max) {
				if(n > 2 && (i == 0 || i == (n-1)) && basic_add != 0) {
					continue;
				}
				temp_max = cnt_class[i][j];
			}
		}
	}
	
	//std::cout << temp_max << " " << temp_min << " " << sergei << " " << cnt_class[x-1][y-1] << std::endl;

	sergei += cnt_class[x-1][y-1];
	cnt_max += temp_max;
	cnt_min += temp_min;
	std::cout << cnt_max << " " << cnt_min << " " << sergei << std::endl;
	return 0;
}