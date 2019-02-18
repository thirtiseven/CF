#include <vector>
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>

std::vector<int> ans;

using namespace std;
typedef long long LL;
const int MAXN=1e5+5;
const LL INF=2e18;
//const int INF=0x3f3f3f3f;//根据是否超long long修改
LL a[MAXN];

//线段树节点结构体
struct Node{
	int left,right;//左右边界
	LL mi,ma;//最小值 最大值
	LL sum;//和
	LL add;//增减标记
	int set;//重置标记
}tree[MAXN*4];//空间开四倍

//向上更新
void PushUp(int rt){
	int lson=rt<<1,rson=rt<<1|1;
	tree[rt].mi=min(tree[lson].mi,tree[rson].mi);
	tree[rt].ma=max(tree[lson].ma,tree[rson].ma);
	tree[rt].sum=tree[lson].sum+tree[rson].sum;
}

//向下传递标记
void PushDown(int rt){
	if(tree[rt].left<tree[rt].right){//如果不是叶子
		int lson=rt<<1,rson=rt<<1|1;
		if(tree[rt].set!=-1){//set初始为一个不会重置到的数，这里是-1
			tree[lson].set=tree[rt].set;tree[rson].set=tree[rt].set;
			tree[lson].add=tree[rson].add=0;//add失效
			tree[lson].mi=tree[rson].mi=tree[rt].set;
			tree[lson].ma=tree[rson].ma=tree[rt].set;
			tree[lson].sum=(LL)tree[rt].set*(tree[lson].right-tree[lson].left+1);
			tree[rson].sum=(LL)tree[rt].set*(tree[rson].right-tree[rson].left+1);
			tree[rt].set=-1;
		}
		if(tree[rt].add){
			tree[lson].add+=tree[rt].add;tree[rson].add+=tree[rt].add;
			tree[lson].mi+=tree[rt].add;tree[rson].mi+=tree[rt].add;
			tree[lson].ma+=tree[rt].add;tree[rson].ma+=tree[rt].add;
			tree[lson].sum+=(LL)tree[rt].add*(tree[lson].right-tree[lson].left+1);
			tree[rson].sum+=(LL)tree[rt].add*(tree[rson].right-tree[rson].left+1);
			tree[rt].add=0;
		}
	}
}

//建立函数
void Build(int rt,int L,int R){
	tree[rt].left=L;tree[rt].right=R;tree[rt].add=0;tree[rt].set=-1;
	if(L==R) {tree[rt].sum=tree[rt].mi=tree[rt].ma=a[L]; return;}
	int mid=(tree[rt].left+tree[rt].right)>>1;
	Build(rt<<1,L,mid);//只有Build时LR才会变
	Build(rt<<1|1,mid+1,R);
	PushUp(rt);
}

LL QuerySum(int rt,int L,int R){
	if(R<tree[rt].left||L>tree[rt].right) return  0;
	if(L<=tree[rt].left&&tree[rt].right<=R)  return tree[rt].sum;
	PushDown(rt);
	int mid=(tree[rt].left+tree[rt].right)>>1;
	LL res=0;
	if(L<=mid)  res+=QuerySum(rt<<1,L,R);
	if(R>mid)   res+=QuerySum(rt<<1|1,L,R);
	PushUp(rt);
	return  res;
}

LL QueryMin(int rt,int L,int R){
	if(L<=tree[rt].left&&tree[rt].right<=R) return tree[rt].mi;
	PushDown(rt);
	int mid=(tree[rt].left+tree[rt].right)>>1;
	LL res=INF;
	if(L<=mid) res=min(res,QueryMin(rt<<1,L,R));
	if(R>mid) res=min(res,QueryMin(rt<<1|1,L,R));
	PushUp(rt);
	return  res;
}

LL QueryMax(int rt,int L,int R){
	if(L<=tree[rt].left&&tree[rt].right<=R) return  tree[rt].ma;//完全包含才产生贡献
	PushDown(rt);
	int mid=(tree[rt].left+tree[rt].right)>>1;
	LL res=-INF;
	if(L<=mid) res=max(res,QueryMax(rt<<1,L,R));
	if(R>mid) res=max(res,QueryMax(rt<<1|1,L,R));
	PushUp(rt);
	return  res;
}

void UpdateAdd(int rt,int L,int R,int x){//把区间[L,R]加上x
	if(L<=tree[rt].left&&tree[rt].right<=R){
		tree[rt].add+=x;
		tree[rt].sum+=(LL)x*(tree[rt].right-tree[rt].left+1);
		tree[rt].mi+=x;tree[rt].ma+=x;
		return;
	}
	PushDown(rt);
	int mid=(tree[rt].left+tree[rt].right)>>1;
	if(L<=mid) UpdateAdd(rt<<1,L,R,x);
	if(R>mid) UpdateAdd(rt<<1|1,L,R,x);
	PushUp(rt);
}

void Display(int rt){
	cout<<"-------------"<<endl;
	cout<<"id: "<<rt<<endl;
	cout<<"["<<tree[rt].left<<","<<tree[rt].right<<"]"<<endl;
	cout<<"mi: "<<tree[rt].mi<<endl;
	cout<<"ma: "<<tree[rt].ma<<endl;
	cout<<"sum: "<<tree[rt].sum<<endl;
	cout<<"add: "<<tree[rt].add<<endl;
	cout<<"set: "<<tree[rt].set<<endl;
}

void bfs(int rt){
	queue<int> q;
	while(!q.empty()) q.pop();
	q.push(rt);
	while(!q.empty()){
		int fst=q.front();
		q.pop();
		Display(fst);
		if(tree[fst].right>tree[fst].left){
			q.push(fst<<1);
			q.push(fst<<1|1);
		}
	}
}

void UpdateSet(int rt,int L,int R,int x){//把区间[x,y]置为x
	if(L<=tree[rt].left&&tree[rt].right<=R){
		tree[rt].set=x;
		tree[rt].sum=(LL)x*(tree[rt].right-tree[rt].left+1);
		tree[rt].mi=x;tree[rt].ma=x;
		tree[rt].add=0;
		return;
	}
	PushDown(rt);
	int mid=(tree[rt].left+tree[rt].right)>>1;
	if(L<=mid) UpdateSet(rt<<1,L,R,x);
	if(R>mid){
		UpdateSet(rt<<1|1,L,R,x);
	}
	PushUp(rt);
}

int main(){
	int n, m;//n个数 m次询问
	scanf("%d%d",&n,&m);
	{
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		Build(1,1,n);//建立线段树
		int x, y;
		for (int i = 1; i <= m; i++) {
			scanf("%d %d",&x,&y);
			if (QueryMax(1,x,y) < QueryMax(1,1,n)) {
				UpdateAdd(1,x,y,-1);
				ans.push_back(i);
			} else if (QueryMin(1,x,y) == QueryMin(1,1,n)) {
				UpdateAdd(1,x,y,-1);
				ans.push_back(i);
			} else {
				int aaaaa = QueryMax(1,x,y);
				UpdateAdd(1,x,y,-1);
				if (QueryMax(1,x,y) != aaaaa) {
					UpdateAdd(1,x,y,1);
				} else {
					ans.push_back(i);
				}
			}
		}
		std::cout << QueryMax(1,1,n)-QueryMin(1,1,n) << '\n';
		std::cout << ans.size() << '\n';
		for (auto it: ans) {
			std::cout << it << ' ';
		}
	}
	return 0;
}