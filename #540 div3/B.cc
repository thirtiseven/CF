#include <iostream>

using ll = long long;
const int maxn = 2e5+7;

ll sumodd[maxn], sumeven[maxn], reodd[maxn], reeven[maxn], a[maxn];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	sumeven[0] = sumodd[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (i%2==0) {
			sumeven[i] = sumeven[i-1] + a[i];
			sumodd[i] = sumodd[i-1];
		} else {
			sumeven[i] = sumeven[i-1];
			sumodd[i] = sumodd[i-1] + a[i];
		}
	}
	sumeven[n+1] = sumodd[n+1] = 0;
	for (int i = n; i >= 1; i--) {
		if (i%2==0) {
			reeven[i] = reeven[i+1] + a[i];
			reodd[i] =reodd[i+1];
		} else {
			reeven[i] = reeven[i+1];
			reodd[i] =reodd[i+1] + a[i];
		}
	}
//	for (int i = 1; i <= n; i++) {
//		std::cout << sumeven[i] << " " << sumodd[i] << ' ' << reeven[i] << " " << reodd[i] << '\n';
//	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sumeven[i-1]+reodd[i+1] == sumodd[i-1] + reeven[i+1]) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}