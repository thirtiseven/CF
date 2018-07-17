#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, m, a, b;
	std::cin >> n >> m >> a >> b;
	std::cout << std::min((m-((n+m)%m))*a, ((n+m)%m)*b);
}