#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int q, n, k;
	std::string st1 = "\"What are you doing while sending ";
	std::string st2 = "\"What are you doing at the end of the world? Are you busy? Will you save us?\"";
	std::string st3 = "? Are you busy? Will you send ";
	std::string st4 = "?\"."
	std::cin >> q;
	for(int i = 0; i < q; i++) {
		std::cin >> n >> k;
		if(k<=n*34) {
			std::cout << st1[(k-1)%34];
		} else if(k <= n*34 + 77){
			std::cout << st2[(k-1-n*34)];
		}
	}
	return 0;
}