#include <iostream>
#include <algorithm>

const int maxn = 1e4+2;

int num[maxn];

int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

int main(int argc, char *argv[]) {  
	int T;
	T = read();
	while (T--) {
		int n, t;
		std::fill(num, num+maxn, 0);
		n = read();
		int maxx = 0;
		for (int i = 0; i < n; i++) {
			t = read();
			maxx = std::max(maxx, t);
			num[t]++;
		}
		int ans = 0, nowa = 1, nowb = maxn, cur = 0;
		for (int i = maxx; i >= 1; i--) {
			if (num[i] >= 4) {
				std::cout << i << " " << i << " " << i << " " << i << '\n';
				goto fuck;
			} else if (num[i] >= 2) {
				if (cur == 0) {
					cur = i;
					continue;
				}
				if (1LL*nowa*cur < 1LL*i*nowb) {
					nowb = cur, nowa = i;
				}
				cur = i;
			}
		}
		std::cout << nowa << " " << nowa << " " << nowb << " " << nowb << '\n';
		fuck:;
	}
}