#include <cctype>
#include <cstdio>

using ll = long long;

ll read() {
	ll x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1LL;
}

ll gcd(ll a, ll b) { 
	ll t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

int main(int argc, char *argv[]) {  
	int T = read();
	while (T--) {
		ll p, q, b;
		p = read();
		q = read();
		b = read();
//		std::cin >> p >> q >> b;
		if (p == 0) {
			puts("Finite");
			goto out;
		}
		q /= gcd(p, q);
		q /= gcd(b, q);
		if (q == 1) {
			puts("Finite");
			goto out;
		}
		ll d;
		while((d=gcd(q,b))!=1)
			while(q%d==0) q/=d;
		if (q == 1) {
			puts("Finite");
		} else {
			puts("Infinite");
		}
		out:;
	}
}