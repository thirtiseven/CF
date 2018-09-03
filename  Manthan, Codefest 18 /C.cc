#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string a, b;
	std::cin >> n >> a >> b;
	int ans = 0;
	for (int i = 0; i < n;) {
		if (i < n-1 && a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]) {
			ans++;
			i+=2;
		} else if (a[i] != b[i]) {
			ans++;
			i++;
		} else {
			i++;
		}
	}
	std::cout << ans;
}