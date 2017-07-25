#include <iostream>
#include <cstring>
#include <vector>

int main(int argc, char *argv[]) {  
	int n, m;
	char s[1050], t[1050];
	std::vector<int> pos;
	std::vector<int> temp;
	std::cin >> n >> m;
	std::cin >> s;
	std::cin >> t;
	int ans = 10000, cnt = 0;
	for(int i = 0; i < m; i++) {
		if(m < i + n) {
			break;
		}
		cnt = 0;
		temp.clear();
		for(int j = 0; j < n; j++) {
			if(t[i+j] != s[j]){
				cnt++;
				temp.push_back(j);
			}
		}
		if(cnt < ans) {
			ans = cnt;
			pos = temp;
		}
	}
	std::cout << ans << std::endl;
	for(int i = 0; i < ans; i++){
		std::cout << pos[i]+1 << " ";
	}
	return 0;
}