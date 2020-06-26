#include <iostream>
#include <cctype>

using ll = long long;

template <class T>
inline bool read(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-') ?-1:1 ;
	ret=(c=='-') ?0:(c -'0');
	while(c=getchar(),c>='0'&&c<='9')
		ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

const int maxn = 1e6+7;

ll a[maxn], b[maxn], c[3], n, m, p;

int main(int argc, char *argv[]) {  
	read(n);
	read(m);
	read(p);
	for (int i = 0; i < n; i++) {
		read(a[i]);
	}
	for (int i = 0; i < m; i++) {
		read(b[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % p != 0) {
			ans += i;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (b[i] % p != 0) {
			ans += i;
			break;
		}
  	}
 	std::cout << ans << '\n';
}