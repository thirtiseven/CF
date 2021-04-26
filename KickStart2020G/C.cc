#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>

using uchar=unsigned char;

constexpr int Maxn(1000000);

namespace IOManager{
	constexpr int FILESZ(131072);
	char buf[FILESZ];
	const char*ibuf=buf,*tbuf=buf;
	struct IOManager{
		inline char gc() {
			return (ibuf==tbuf) && (tbuf=(ibuf=buf)+fread(buf,1,FILESZ,stdin),ibuf==tbuf) ? EOF : *ibuf++;
		}

		template<class _Tp>
			inline operator _Tp(){
				_Tp s=0u;char c=gc(),w=0;
				for(;c<48;c=gc())
					c==45&&(w=1);
				for(;c>47;c=gc())
					s=(_Tp)(s*10u+c-48u);
				return w?-s:s;
			}
	};
}IOManager::IOManager io;

const int maxn = 1e5+7;
using ll = long long;

int T, w, n;
ll x[maxn], xx[maxn];

ll gao(ll val) {
	ll ret = 0;
	ll xx, yy;
	for (int i = 0; i < w; i++) {
		xx = std::min(x[i], val), yy = std::max(x[i], val);
		ret += std::min(xx+n-yy, yy-xx);
	}
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
//	std::cin >> T;
	T = io;
	for (int CAS = 1; CAS <= T; CAS++) {
//		std::cin >> w >> n;
		w = io;
		n = io;
		for (int i = 0; i < w; i++) {
//			std::cin >> x[i];
			x[i] = io;
			x[i]--;
			xx[i] = x[i];
		}
		std::sort(x, x+w);
		ll ans = 1e15;
		int minpos = -1;
		int seg = 3*sqrt(w)/2;
		for (int i = 0; i < w; i += seg) {
			ll temp = gao(x[i]);
			if (temp < ans) {
				ans = temp;
				minpos = i;
			}			
		}
		for (int i = (minpos+w-seg/2-2); i < (minpos+w+seg/2+2); i++) {
			ll temp = gao(x[i%w]);
			if (temp < ans) {
				ans = temp;
				minpos = i;
			}			
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}