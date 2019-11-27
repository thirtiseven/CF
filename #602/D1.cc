#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 2e5+7;
const int N = 200010, INF = 1e9;

int n, m, k, pos, bb[maxn];

struct SegmentTree 
{
	int lc, rc; // 左右子节点编号
	int sum;   //sum记录当前区间内数的个数
} tree[N * 80];
int t = 0, tot, a[N], b[N], root[N];

int build(int l, int r)
{
	int p = ++tot; // 新建一个节点，编号为p，代表当前区间[l,r]
	tree[p].sum = 0;
	if (l == r) return p;
	int mid = (l + r) >> 1;
	tree[p].lc = build(l, mid);
	tree[p].rc = build(mid + 1, r);
	return p;
}
int insert(int now, int l, int r, int x, int delta)//值为x的数增加delta个
{
	int p = ++tot;
	tree[p] = tree[now]; // 新建一个副本
	if (l == r) 
	{
		tree[p].sum += delta; // 在副本上修改
		return p;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) tree[p].lc = insert(tree[now].lc, l, mid, x, delta);
	else tree[p].rc = insert(tree[now].rc, mid + 1, r, x, delta);
	tree[p].sum = tree[tree[p].lc].sum + tree[tree[p].rc].sum;
	return p;
}
int ask(int p, int q, int l, int r, int k)//[q,p]内第k个小的值
{
	if (l == r) return l; // 找到答案
	int mid = (l + r) >> 1;
	int lcnt = tree[tree[p].lc].sum - tree[tree[q].lc].sum; // 值在[l,mid]中的数有多少个
	if (k <= lcnt) return ask(tree[p].lc, tree[q].lc, l, mid, k);
	else return ask(tree[p].rc, tree[q].rc, mid + 1, r, k - lcnt);
}

std::pair<int, int> xx[maxn];

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {	
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> xx[i].first;
		xx[i].second = i;
		bb[i] = xx[i].first;
	}
	std::sort(xx+1, xx+n+1, cmp);
	for (int i = 1; i <= n; i++) 
	{
		a[i] = xx[i].second;
		b[++t] = a[i];
	}
	std::cin >> m;
	std::sort(b + 1, b + t + 1); // 离散化
	t = std::unique(b + 1, b + t + 1) - (b + 1);
	root[0] = build(1, t); // 关于离散化后的值域建树
	for (int i = 1; i <= n; i++)  {
		int x = std::lower_bound(b + 1, b + t + 1, a[i]) - b; // 离散化后的值
		root[i] = insert(root[i - 1], 1, t, x, 1); // 值为x的数增加1个
	}
	while (m--) {
		std::cin >> k >> pos;
		int l = 1, r = k, xxx = pos;
		std::cout << bb[b[ask(root[r], root[l - 1], 1, t, xxx)]] << '\n';
	}
}