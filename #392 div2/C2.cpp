#include <iostream>
#include <cstring>
#include <algorithm>

#define ll long long
#define inf 1000000000

ll n, m, k, x, y;
ll sergei = 0, cnt_max = 0, cnt_min = 0;

int cnt_class[110][110];

int main(int argc, char *argv[]) {  
	memset(cnt_class, 0, sizeof(cnt_class));
	std::cin >> n >> m >> k >> x >> y;
	ll div;
	int temp_min = inf, temp_max = -1;
	if(n == 1) {
		div = 2 ;
		ll left = k % m;
		ll cnt_one = k / m;
		for(int i = 0; i < m; i++) {
			cnt_class[0][i] += cnt_one;
		}
		for(int i = 0; i < m; i++) {
	 		if(left) {
				cnt_class[0][i]++; 
				left--;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(cnt_class[i][j] > temp_max) {
					temp_max = cnt_class[i][j];
				}
				if(cnt_class[i][j] < temp_min) {
					temp_min = cnt_class[i][j];
				}
			}
		}
		sergei += cnt_class[x-1][y-1];
		cnt_max += temp_max;
		cnt_min += temp_min;
		std::cout << cnt_max << " " << cnt_min << " " << sergei << std::endl;
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
	cnt_max += 2 * basic_add;
	cnt_min += basic_add;
	k %= (div * m);
	
	//std::cout << div << " " << k << " " << basic_add << " " << (2 * n * m) << std::endl;
	
	for(int i=0;i<n && k;i++)  
	{  
		for(int j=0;j<m && k;j++)  
		{  
			if(k)  
			{  
				cnt_class[i][j]++;  
				k--;  
			}  
		}  
	}  
	for(int i=n-2;i>0 && k;i--)  
	{  
		for(int j=0;j<m && k;j++)  
		{  
			if(k)  
			{  
				cnt_class[i][j]++;  
				k--;  
			}  
		}  
	}
	
	temp_min = inf;
	temp_max = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(cnt_class[i][j] > temp_max) {
				temp_max = cnt_class[i][j];
			}
			if(cnt_class[i][j] < temp_min) {
				temp_min = cnt_class[i][j];
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