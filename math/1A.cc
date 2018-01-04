#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, m, a;
	std::cin >> n >> m >> a;
	long long l = n/a;
	long long r = m/a;
	if(n%a) l++;
	if(m%a) r++;
	std::cout << l * r << std::endl;
	return 0;
}