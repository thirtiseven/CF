#include <iostream>
#include <algorithm>
#include <vector>

//A为原始数组，sum记录区间和，Add为懒惰标记

const int maxn = 150009;
const int inf = 4e8+1;
int A[maxn], sum[maxn << 2];

void pushup(int rt) {
	sum[rt] = std::min(sum[rt << 1], sum[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = A[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//点修改
void update(int index, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (index <= mid) update(index, val, l, mid, rt << 1);
	else update(index, val, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

int n1, n2, n3, n4, a[4][maxn];
int m1, m2, m3, x, y;
std::vector<int> t1[maxn], t2[maxn], t3[maxn];
int ans[4][maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n1 >> n2 >> n3 >> n4;
	for (int i = 1; i <= n1; i++) {
		std::cin >> a[0][i];
	}
	for (int i = 1; i <= n2; i++) {
		std::cin >> a[1][i];
	}
	for (int i = 1; i <= n3; i++) {
		std::cin >> a[2][i];
	}
	for (int i = 1; i <= n4; i++) {
		std::cin >> a[3][i];
	}
	std::cin >> m1;
	for (int i = 0; i < m1; i++) {
		std::cin >> x >> y;
		t1[y].push_back(x);
	}
	std::cin >> m2;
	for (int i = 0; i < m2; i++) {
		std::cin >> x >> y;
		t2[y].push_back(x);
	}
	std::cin >> m3;
	for (int i = 0; i < m3; i++) {
		std::cin >> x >> y;
		t3[y].push_back(x);
	}
	for (int i = 1; i <= n1; i++) {
		A[i] = a[0][i];
	}
	build(1, n1, 1);
	for (int i = 1; i <= n2; i++) {
		for (auto it: t1[i]) {
			update(it, inf, 1, n1, 1);
		}
		ans[1][i] = sum[1] + a[1][i];
		for (auto it: t1[i]) {
			update(it, a[0][it], 1, n1, 1);
		}
	}
	for (int i = 1; i <= n2; i++) {
		A[i] = ans[1][i];
	}
	build(1, n2, 1);
	for (int i = 1; i <= n3; i++) {
		for (auto it: t2[i]) {
			update(it, inf, 1, n2, 1);
		}
		ans[2][i] = sum[1] + a[2][i];
		for (auto it: t2[i]) {
			update(it, ans[1][it], 1, n2, 1);
		}
	}
	for (int i = 1; i <= n3; i++) {
		A[i] = ans[2][i];
	}
	build(1, n3, 1);
	for (int i = 1; i <= n4; i++) {
		for (auto it: t3[i]) {
			update(it, inf, 1, n3, 1);
		}
		ans[3][i] = sum[1] + a[3][i];
		for (auto it: t3[i]) {
			update(it, ans[2][it], 1, n3, 1);
		}
	}
	int final_ans = inf;
	for (int i = 1; i <= n4; i++) {
		final_ans = std::min(final_ans, ans[3][i]);
	}
	if (final_ans >= inf) {
		final_ans = -1;
	}
	std::cout << final_ans << '\n';
}