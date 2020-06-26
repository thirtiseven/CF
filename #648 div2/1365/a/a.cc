#include <iostream>
#include <algorithm>

const int maxn = 52;

int T, a[maxn][maxn], n, m, visn[maxn], vism[maxn], sumn, summ;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::fill(visn, visn+maxn, 0);
		std::fill(vism, vism+maxn, 0);
		sumn = summ = 0;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cin >> a[i][j];
				if (a[i][j] == 1) {
					visn[i] = 1;
					vism[j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			sumn += visn[i];
		}
		for (int i = 0; i < m; i++) {
			summ += vism[i];
		}
		int x = std::min(n-sumn, m-summ);
		std::cout << (x%2==0?"Vivek":"Ashish") << '\n';
	}
}