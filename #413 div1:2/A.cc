#include <iostream>

int main(int argc, char *argv[]) {  
	int n, t, k, d;
	std::cin >> n >> t >> k >> d;
	int p1=n/k+(n%k==0?0:1);
	p1*=t; 
	int p2=d+t;
	if(p1 <= p2) {
		std::cout << "NO";
	} else {
		std::cout << "YES";
		
	}
	return 0;
}