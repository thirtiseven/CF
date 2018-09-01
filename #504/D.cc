#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int n, q, num[maxn];
int minnn[maxn], maxxx[maxn];


struct node
{
	int left,right,val;//每个节点有三个值，左区间，右区间，和最小值
}c[maxn*4];
void build_tree(int l,int r,int root)//建树
{
	c[root].left=l;
	c[root].right=r;
	if(l==r)//如果左区间等于右区间就赋值
	{
		c[root].val=num[l];
		return ;
	}
	int mid=(l+r)/2;
	build_tree(l,mid,root*2);
	build_tree(mid+1,r,root*2+1);
	c[root].val=std::min(c[root*2].val,c[root*2+1].val);//递归得到
}
void find_tree(int l,int r,int &min1,int root)//查找
{
	if(c[root].left==l&&c[root].right==r)
	{
		min1=c[root].val;
		return ;
	}
	int mid=(c[root].left+c[root].right)/2;
	if(mid<l)//先找到所要寻找的区间在树上的区间范围
	find_tree(l,r,min1,root*2+1);
	else if(mid>=r)
	find_tree(l,r,min1,root*2);
	else//找到了所要找的区间
	{
		int min2;
		find_tree(l,mid,min1,root*2);//左儿子一个最小值
		find_tree(mid+1,r,min2,root*2+1);//右儿子一个最小值
		min1=std::min(min1,min2);//选最小的
	}
	
}

int main(int argc, char *argv[]) {  
	int zero = 0;
	std::fill(maxxx, maxxx+maxn, 0);
	std::fill(minnn, minnn+maxn, maxn);
	std::cin >> n >> q;
	int yes = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> num[i];
		if (num[i] > q) {
			yes = 0;
		}
	}
	if (yes == 0) {
		std::cout << "NO";
		exit(0);
	}
	
	if (num[1] == 0) {
		zero = 1;
		num[1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (num[i] == 0) {
			if (zero == 0) {
				zero = i;
			}
			zero = i;
			num[i] = num[i-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		minnn[num[i]] = std::min(minnn[num[i]], i);
		maxxx[num[i]] = std::max(maxxx[num[i]], i);
	}
	if (minnn[q] == maxn && !zero) {
		std::cout << "NO";
		exit(0);
	}
	if (minnn[q] == maxn && zero) {
		num[zero] = q;
	}
	build_tree(1, n, 1);
	int aaa;
	for (int i = 1; i <= q; i++) {
		if (minnn[i] < maxn && maxxx[i] > 0 && minnn[i] != maxxx[i]) {
			find_tree(minnn[i], maxxx[i], aaa ,1);
//			std::cout << minnn[i] << " " << maxxx[i] << " " << aaa << '\n';
			if (aaa < i) {
				yes = 0;
				break;
			}
		}
	}
	if (yes == 0) {
		std::cout << "NO";
		exit(0);
	}
	std::cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		std::cout << num[i] << " ";
	}
}