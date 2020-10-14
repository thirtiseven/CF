#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int T;
	std::cin>>T;
	while(T--){
		int n,flag=1;
		std::string s;
		std::cin>>n>>s;
		for(int i = 0, j = n-1; i < j; i++, j--){
			if (s[i] == s[j]) {
				continue;
			}
			if (!(std::abs(s[i]-s[j])==2)) {
				flag = 0;
			}
		}
		std::cout << (flag?"YES\n":"NO\n");
	}
}