#include <iostream>
#include <algorithm>

#define maxn 200010
#define inf 0x7f7f7f7f 

struct voucher{
	int l, r, cost, time;
}v[maxn];

int mincost = inf;

bool cmp(voucher a, voucher b) {
	return a.time < b.time;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	int n, x;
	std::cin >> n >> x;
	int tl, tr, tc, tt;
	for(int i = 0; i < n; i++) {
		std::cin >> tl >> tr >> tc;
		tt = tr - tl + 1;
		if(tt >= x) {
			n--;
			i--;
		} else {
			v[i].l = tl;
			v[i].r = tr;
			v[i].cost = tc;
			v[i].time = tt;
		}
	}
	std::sort(v, v+n, cmp);
	int tempcost, flag = 0;
	for(int i = 0; i < n; i++) {
		if(v[i].time != v[i+1].time) {
			n -= flag;
		}
		for(int j = n-1; j > i; j--) {
			flag = 0;
			if(v[i].time + v[j].time == x) {
				if (v[i].r < v[j].l || v[j].r < v[i].l) {
					tempcost = v[i].cost + v[j].cost;
					if(tempcost < mincost) {
						mincost = tempcost;
					}
				}
				flag++;
			}
		}
	}
	if(mincost == inf) {
		std::cout << "-1\n";
	} else {
		std::cout << mincost << std::endl;
	}
	return 0;
}