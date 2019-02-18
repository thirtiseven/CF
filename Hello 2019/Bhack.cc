#include <iostream>

bool yes = 0;
int n, a[20];

void dfs(int tot, int now) {
	if (tot == n && now == 360) {
		yes = 1;
	}
	if (tot == n) {
		return;
	}
	dfs(tot+1, now+a[tot]);
	dfs(tot+1, now-a[tot]);
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	dfs(0, 0);
	if (yes) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}