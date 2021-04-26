#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
const int maxa = 5e6+7;

int n;
int a[maxn], x[maxa], y[maxa];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (x[a[i]+a[j]] > 0 && x[a[i]+a[j]] != i && y[a[i]+a[j]] != i &&  y[a[i]+a[j]] != j) {
				std::cout << "YES\n";
				std::cout << x[a[i]+a[j]] << ' ' << y[a[i]+a[j]] << ' ' << i << ' ' << j << '\n';
				goto end;
			}
			x[a[i]+a[j]] = i;
			y[a[i]+a[j]] = j;
		}
	}
	std::cout << "NO\n";
	end:;
}