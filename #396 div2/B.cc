#include <iostream>
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  

#define maxn 100010

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int edge[maxn];
	for(int i = 0; i < n; i++) {
		std::cin >> edge[i];
	}
	std::sort(edge, edge + n);
	for(int i = 0; i < n - 2; i++) {
		if(edge[i] + edge[i+1] > edge[i+2]) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}