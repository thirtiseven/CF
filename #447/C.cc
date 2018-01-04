#include <iostream>
#include <set>

#define ll int

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	int n, a[3010];
	std::set<int> aa;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		aa.insert(a[i]);
	}
	int gccccd = a[0];
	for(int i = 1; i < n; i++) {
		gccccd = gcd(gccccd, a[i]);
	}
	if(aa.count(gccccd) == 0) {
		std::cout << "-1" << std::endl;
	} else {
		std::cout << n*2-1 << '\n' << a[0];
		for(int i = 1; i < n; i++) {
			std::cout << " " << gccccd << " " << a[i];
		}
	}
	return 0;
}