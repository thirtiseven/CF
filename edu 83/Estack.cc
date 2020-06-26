#include <iostream>
#include <stack>

const int maxn = 500+7;

int n, dp[maxn], a[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		std::stack<int> s;
		s.push(a[i]);
		dp[i] = dp[i-1]+1;
		for (int j = i-1; j >= 1; j--) {
			int num = a[j];
			while(!s.empty() && s.top()==num) {
				s.pop();
				num++;
			}
			s.push(num);	
			dp[i] = std::min(dp[i], dp[j-1]+(int)s.size());
		}
	}
	std::cout << dp[n] << '\n';
}