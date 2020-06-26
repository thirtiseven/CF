#include <iostream>
#include <algorithm>

const int maxn = 4e5+7;

int t, n, k, a[maxn];
int sum[maxn << 2], Add[maxn << 2];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int l, int r) {
	if (Add[rt]) {
		int mid = (l + r) >> 1;
		Add[rt << 1] += Add[rt];
		Add[rt << 1 | 1] += Add[rt];
		sum[rt << 1] += (mid - l + 1)*Add[rt];
		sum[rt << 1 | 1] += (r - mid)*Add[rt];
		Add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//区间加值
void update(int L, int R, int val, int l, int r, int rt) {
	if (L <= l && R >= r) {
		Add[rt] += val;
		sum[rt] += (r - l + 1)*val;
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid)update(L, R, val, l, mid, rt << 1);
	if (R > mid)update(L, R, val, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//点修改
void update(int index, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (index <= mid)update(index, val, l, mid, rt << 1);
	else update(index, val, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//区间查询
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && R >= r) {
		return sum[rt];
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid)ret += query(L, R, l, mid, rt << 1);
	if (R > mid)ret += query(L, R, mid + 1, r, rt << 1 | 1);
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k;
		std::fill(Add, Add+8*k, 0);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		build(1, 2*k, 1);
		for (int i = 1; i <= n/2; i++) {
			int A, B, C, D;
			B = a[i] + a[n-i+1] - 1;
			C = a[i] + a[n-i+1] + 1;
			A = B - (std::max(a[i], a[n-i+1]) - 1);
			D = C + (k - std::min(a[i], a[n-i+1]));
//			std::cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';
			if (B > A) {
				update(A+1, B, 1, 1, 2*k, 1);
			}
			if (D > C) {
				update(C, D-1, 1, 1, 2*k, 1);
			}
			if(A >= 1) update(1, A, 2, 1, 2*k, 1);
			if (D <= 2*k) update(D, 2*k, 2, 1, 2*k, 1);
		}
		int ans = 100000000;
		for (int i = 2; i <= 2*k; i++) {
			ans = std::min(ans, query(i, i, 1, 2*k, 1));
		}
		std::cout << ans << '\n';
	}
}