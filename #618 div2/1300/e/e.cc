#include <iostream>
#include <iomanip>

const int maxn = 1e6+7;

int n;
double a[maxn], pre[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int x = 60;
	while (x--) {
		pre[0] = 0;
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i-1] + a[i];
		}
		for (int i = 1; i <= n;) {
			double now = a[i];
			int x = 1;
			while (i+x<=n && a[i+x]*(x) < pre[i+x-1]-pre[i-1]) {
				x++;
			}
			double temp = double(pre[i+x-1]-pre[i-1])/double(x);
			for (int j = i; j < i+x; j++) {
				a[j] = temp;
			}
			i += x;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << std::fixed << std::setprecision(9) << a[i] << '\n';
	}
}