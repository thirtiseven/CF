#include <iostream>
#include <string>

int n, k, t;
std::string s;
int cnt[30];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k >> s;
		int ans = 0, maxx = 0;
		for (int j = 0; j < k/2; j++) {
			std::fill(cnt, cnt+26, 0);
			for (int i = 0; i < n/k; i++) {
				cnt[int(s[i*k+j]-'a')]++;
				cnt[int(s[i*k+k-1-j]-'a')]++;
			}
			maxx = 0;
			for (int i = 0; i < 26; i++) {
				maxx = std::max(maxx, cnt[i]);
			}
//			std::cout << (n/k*2-maxx) << '\n';
			ans += (n/k*2-maxx);
		}
		if (k % 2 == 1) {
			std::fill(cnt, cnt+26, 0);
			for (int i = 0; i < n/k; i++) {
				cnt[int(s[i*k+k/2]-'a')]++;
//				std::cout << s[i*k+k/2] << '\n';
			}
			maxx = 0;
			for (int i = 0; i < 26; i++) {
				maxx = std::max(maxx, cnt[i]);
			}
//			std::cout << (n/k-maxx) << '\n';
			ans += (n/k-maxx);			
		}
		std::cout << ans << '\n';
	}
}