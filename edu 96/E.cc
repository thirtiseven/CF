#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 200003;
int n;
std::string s;

//A为原始数组，sum记录区间和，Add为懒惰标记

int A[27][maxn], Max[27][maxn << 2], Lazy[27][maxn << 2];

void pushup(int rt, int idx) {
	Max[idx][rt] = std::max(Max[idx][rt << 1], Max[idx][rt << 1 | 1]);
}

void pushdown(int rt, int l, int r, int idx) {
	if (Lazy[idx][rt]) {
		int mid = (l + r) >> 1;
		Lazy[idx][rt << 1] += Lazy[idx][rt];
		Lazy[idx][rt << 1 | 1] += Lazy[idx][rt];
		Max[idx][rt << 1] += (mid - l + 1)*Lazy[idx][rt];
		Max[idx][rt << 1 | 1] += (r - mid)*Lazy[idx][rt];
		Lazy[idx][rt] = 0;
	}
}

void build(int l, int r, int rt, int idx) {
	if (l == r) {
		Max[idx][rt] = A[idx][l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1, idx);
	build(mid + 1, r, rt << 1 | 1, idx);
	pushup(rt, idx);
}

//区间加值
void update(int L, int R, int val, int l, int r, int rt, int idx) {
	if (L <= l && R >= r) {
		Lazy[idx][rt] += val;
		Max[idx][rt] += (r - l + 1)*val;
		return;
	}
	pushdown(rt, l, r, idx);
	int mid = (l + r) >> 1;
	if (L <= mid)update(L, R, val, l, mid, rt << 1, idx);
	if (R > mid)update(L, R, val, mid + 1, r, rt << 1 | 1, idx);
	pushup(rt, idx);
}

//点修改
void update(int index, int val, int l, int r, int rt, int idx) {
	if (l == r) {
		Max[idx][rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (index <= mid)update(index, val, l, mid, rt << 1, idx);
	else update(index, val, mid + 1, r, rt << 1 | 1, idx);
	pushup(rt, idx);
}

//区间查询
int query(int L, int R, int l, int r, int rt, int idx) {
	if (L <= l && R >= r) {
		return Max[idx][rt];
	}
	pushdown(rt, l, r, idx);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid) ret = std::max(query(L, R, l, mid, rt << 1, idx), ret);
	if (R > mid) ret = std::max(query(L, R, mid + 1, r, rt << 1 | 1, idx), ret);
	return ret;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> s;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			A[j][i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		A[int(s[i]-'a')][i+1] = i+1;
	}
	for (int i = 0; i < 26; i++) {
		build(1, n, 1, i);
	}
	std::reverse(s.begin(), s.end());
	int upper = n;
	long long ans = 0;
	for (int i = n-1; i >= 0; i--) {
		std::cerr << "! ";
		int pos = query(1, upper, 1, n, 1, int(s[i]-'a')) - 1;
		std::cerr << pos << ' ' << i << '\n';
		ans += (long long)(i-pos);
		if (i != pos) {
//			upper--;
			for (int i = 0; i < 26; i++) {
				update(pos, -10000, 1, n, 1, i);
				update(pos, n, -1, 1, n, 1, i);
			}
		}
	}
	std::cout << ans << '\n';
}