#include <iostream>
#include <cmath>
#include <cstring>

#define ll long long

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false); 
	ll t,n;
	while(std::cin>>t) {
		while(t--) {
			std::cin>>n;
			// cout<<n<<" ";
			if(n<4 || n==5 || n==7 || n==11) {
				std::cout<<"-1\n";
				continue;
			}
			if(n%4==0) {
				std::cout<<(n/4)<<"\n";
				continue;
			}
			if(n-6>=0 && (n-6)%4==0) {
				std::cout<<((n-6)/4)+1<<"\n";
				continue;
			}
			if(n-9>=0 && (n-9)%4==0) {
				std::cout<<((n-9)/4)+1<<"\n";
				continue;
			}
			if(n-15>=0 && (n-15)%4==0) {
				std::cout<<((n-15)/4)+2<<"\n";
				continue;
			}
			std::cout<<"-1\n";
		}
	}
	return 0;
	return 0;
}