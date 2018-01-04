#include <iostream>
typedef long long LL;
const int Maxn = 1000 + 10;
LL CArr[Maxn + 10][Maxn + 10];
void CInit(int n) {
for (int i = 0; i <= n; i++) {
CArr[i][0] = CArr[i][i] = 1;
for (int j = 1; j < i; j++)
CArr[i][j] = (CArr[i - 1][j - 1] + CArr[i - 1][j]);
}}

LL C(int n, int m) { return CArr[n][m];
}


int main(int argc, char *argv[]) {  
	LL n, k;
	LL kk[5] = {0, 0, 1, 2, 9};
	std::cin >> n >> k;
	CInit(n);
	LL ans = 1;
	for(int i = 2; i <= k; i++) {
		ans += (C(n, n-i) * kk[i]);
		//std::cout << C(n, n-i) << " " << kk[i] << " ";
	}
	std::cout << ans << std::endl;
	return 0;
}