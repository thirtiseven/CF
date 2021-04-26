#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1e5+7;

int n, p, k, x, y;
std::string s;
int num[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> n >> p >> k >> s >> x >> y;
		for (int i = 0; i < k; i++) {
			num[i] = 0;
		}
//		std::cout << "--------\n";
		for (int i = p; i < n; i++) {
			if (s[i] == '0') {
//				std::cout << s[i] << ' ' << i%k << '\n';
				num[i%k]++;
			}
		}
//		for (int i = 0; i < k; i++) {
//			std::cout << num[i] << " \n"[i==k-1];
//		}
		int ans = num[(p+2*k-2)%k]*x + int(s[p-1]=='0')*x;
		int overall = 0;
		for (int i = 0; i < k; i++) {
			overall += y;			
			std::cout << overall + num[i]*x + int(s[p-1+i]=='0')*x << '\n';
			ans = std::min(ans, overall + num[(p+i+1)%k]*x + int(s[p-1+i]=='0')*x);
			if (s[p+i] == '0') {
				num[(p+i)%k]--;
			}
		}
		std::cout << ans << '\n';
	}
}