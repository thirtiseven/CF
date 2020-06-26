#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int T, n, a[maxn];

template<class Cmp>  
int LIS (Cmp cmp) {  
	static int m, end[maxn];  
	m = 0;  
	for (int i=0; i<n; i++) {  
		int pos = lower_bound(end, end+m, a[i], cmp)-end;  
		end[pos] = a[i], m += pos==m;  
	}  
	return m;  
}  

bool greater1(int value) {  
	return value >=1;  
}  

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::cout << n - LIS(std::less_equal<int>()) << '\n';   //非严格上升 
	}
}