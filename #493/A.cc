#include <iostream>

int n, a[1234], sum = 0;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	if ((sum%2==0&&n==2&&a[0]==a[1])||(n==1)) {
		std::cout << -1;
	} else if(a[0] != sum/2) {
		std::cout << "1\n1\n";
	} else {
		std::cout << "1\n2\n";
	}
}