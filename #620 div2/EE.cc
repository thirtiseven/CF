#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 4e5+10;
int n,q,num_edge;
int f[maxn],depth[maxn];
//f记录父节点，depth记录深度
int st[30][maxn];
//第一维i表示跳2^i层，第二维j表示开始跳的起点
//数组内存的数据表示跳到的终点
int first[maxn],Next[2*maxn],v[2*maxn];
//v记录边的终点,Next记录上一条边的标号
//first记录最后一条边的标号
void road(int x,int y) //记录从x到y的一条边
{
	v[++num_edge]=y;//记录终点为y
	Next[num_edge]=first[x];//新边指向之前的最后一条变
	first[x]=num_edge;//更新最后一条边
}
void dfs(int son,int father) {
	f[son]=father;//记录son点的父节点
	//将从son出发的每条边都进行进一步的深搜
	for(int i = first[son]; i!=-1; i=Next[i])
	{
		int to = v[i];//取出遍历到的边的终点
		if(to==father)continue;//防止死循环
		depth[to]=depth[son]+1;
		dfs(to,son);
	}
}
int get_lca(int x,int y) {
	if(depth[x]<depth[y])swap(x,y);//保证x比y深
	//使x到达与y的共同深度
	for(int i = 20; i >= 0; i--)
		if(depth[st[i][x]]>=depth[y])
			x=st[i][x];
	//如果y就是x的父节点，则两者的第一个共同根节点就是y
	if(x==y)return x;
	//一步步往上跳以寻找xy的最后一个依旧不相同的根节点
	for(int i = 20; i >= 0; i--)
		if(st[i][x]!=st[i][y])
			x=st[i][x],y=st[i][y];
	//最后一个不相同根节点的父节点即所求答案
	return f[x];
}

int gao(int u, int v) {
	int father = get_lca(u, v);
	return depth[u]+depth[v]-2*depth[father];
}

int main() {
	int x,y;
	cin >> n;
	memset(first,-1,sizeof(first));
	num_edge=0;
	//存下每一条边
	for(int i = 1; i < n; i++) {
		std::cin >> x >> y;
		road(x,y),road(y,x);
	}
	//预处理depth
	depth[1]=1;//根节点深度为1
	dfs(1,0);//处理剩余的depth
	//准备st表
	//如果跳2^0层即跳一层，则会跳到自己的父节点
	for(int i = 1; i <= n; i++)
		st[0][i]=f[i];
	//如果从j跳2^i层能到达st[i][j]
	//因为2^(i-1)+2^(i-1)=2^i
	//那么从j跳2^(i-1)层所到达的点再跳2^(i-1)层也能到st[i][j]
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= n; j++)
			st[i][j]=st[i-1][st[i-1][j]];
	//q次查询
	std::cin >> q;
	int a, b, k;
	while(q--)
	{
		std::cin >> a >> b >> x >> y >> k;
		bool yes = 0;
		int res = gao(x, y), res2 = gao(x, a)+gao(b, y)+1, res3 = gao(x, b)+gao(y, a)+1;
//		std::cout << res << ' ' << res2 << ' ' << res3 << '\n';
		if (res <= k && (res-k)%2==0) {
			yes = 1;
		} else if (res2 <= k && (res2-k)%2==0) {
			yes = 1;
		} else if (res3 <= k && (res3-k)%2==0) {
			yes = 1;
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
	return 0;
}