#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
const int maxn=50005;
#define maxn 100005
struct node
{
	int to,next;
}edg[maxn<<1];
int eid,head[maxn];
int fa[maxn],deep[maxn],top[maxn],size[maxn],son[maxn],p[maxn],pos;     //p 建树顺序
void init()
{
	pos=0;                                  //树顺序
	eid=0;                                  //前向星顺序
	memset(head,-1,sizeof(head));
}
void addedge(int u,int v)                  //前向星
{
	edg[eid].to=v;
	edg[eid].next=head[u];
	head[u]=eid++;
	edg[eid].to=u;
	edg[eid].next=head[v];
	head[v]=eid++;
}

void dfs(int u,int pre,int d)  {          
	fa[u]=pre;                          
	size[u]=1;
	deep[u]=d;
	son[u]=-1;
	for(int i=head[u];i!=-1;i=edg[i].next) {
		int v=edg[i].to;
		if(v==pre)
			continue;
		dfs(v,u,d+1);
		size[u]+=size[v];
		if(son[u]==-1||size[son[u]]<size[v])
			son[u]=v;
	}
}

void getpos(int u,int root) {           //二次dfs 根据链顺序给pos
	top[u]=root;
	p[u]=++pos;
	if(son[u]==-1) {
		return;
	}
	getpos(son[u],root);
	for(int i=head[u];i!=-1;i=edg[i].next) {
		int v=edg[i].to;
		if(son[u]==v||v==fa[u])
			continue;
		getpos(v,v);
	}
}

int root[maxn*3];
int a[maxn];
void build(int l,int r,int rt) {
	if(l==r) {
		root[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,lr);
	build (m+1,r,rr);
	root[rt]=root[lr]^root[rr];
}

int query(int l,int r,int rt,int L,int R) {
	if(L<=l&&r<=R) {
		return root[rt];
	}
	int mid=(l+r)/2,ans=0;
	if(L<=mid)
		ans^=query(l,mid,lr,L,R);
	if(mid<R)
		ans^=query(mid+1,r,rr,L,R);
	return ans;
}

int operat(int u,int v) {
	int fu=top[u],fv=top[v],ans=0;
	while(fu!=fv) {                           //不在同一条链上就 跳链
		if(deep[fu]<deep[fv]) {
			swap(fu,fv);
			swap(u,v);
		}
		ans^=query(1,pos,1,p[fu],p[u]);
		u=fa[fu];
		fu=top[u];
	}
	if(deep[u]>deep[v])
		swap(u,v);
	ans^=query(1,pos,1,p[u],p[v]);
	ans --;
	return ans;
}

int main(int argc, char *argv[]) {
	int T,n,q,val[maxn],u,v;
	std::cin >> n;
	init();
	for(int i=1;i<n;i++) {
		std::cin >> u >> v;
		addedge(u, v);
	}
	for(int i = 1; i <= n; i++) {
		val[i] = 1;
	}
	dfs(1,1,1);
	getpos(1,1);
	for(int i=1;i<=n;i++) {
		a[p[i]]=val[i];
	}
	build(1,pos,1);
	int x, y, a, b, k;
	std::cin >> q;
	while (q--) {
		std::cin >> x >> y >> a >> b >> k;
		bool yes = 0;
		int res = operat(x, y), res2 = operat(x, a)+operat(b, y)+1, res3 = operat(x, b)+operat(y, a)+1;
		std::cout << res << ' ' << res2 << ' ' << res3 << '\n';
		if (res >= k && (res-k)%2==0) {
			yes = 1;
		} else if (res2 >= k && (res2-k)%2==0) {
			yes = 1;
		} else if (res3 >= k && (res3-k)%2==0) {
			yes = 1;
		}
		std::cout << (yes?"YES\n":"NO\n");
	}
}