#include <iostream>
#include <string>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	int n;
	std::string a, b;
	std::cin >> n >> a >> b;
	long long ans = 0;
	long long zo = 0, zz = 0, oo = 0, oz = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') {
			if (b[i] == '0') {
				zz++;
			} else {
				zo++;
			}
		} else {
			if (b[i] == '0') {
				oz++;
			} else {
				oo++;
			}
		}
	}
	std::cout << oz*(zz+zo) + zz*(oo);
}