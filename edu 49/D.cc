#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 2e5+7;
int ans = 0;
int in[maxn], a[maxn];
int cost[maxn];

int top;//栈顶位置
int Bcnt;//强连通分量编号
int Index;//时间顺序
int DFN[maxn];//时间戳
int LOW[maxn];
int belong[maxn];//顶点i属于哪个强连通分量
int Stack[maxn];//栈
int instack[maxn];//是否在栈内
int n,m;
struct node {
	int to;
	int next;
} edge[maxn];
int head[maxn];
bool Judge[maxn];
int ansi;
void init() {
	std::fill(head,head+n+1,-1);
	std::fill(DFN,DFN+n+1,0);
	std::fill(Judge,Judge+n+1,true);
	ansi=0;
	top=0;
	Bcnt=0;
	Index=0;
}
void add(int a,int b) {
	edge[ansi].to=b;
	edge[ansi].next=head[a];
	head[a]=ansi++;
}
void read() {
	for(int i=1; i<=n; i++) {
		std::cin >> a[i];
		add(i,a[i]);
	}
}
void tarjan(int i) {
	int j,k;
	DFN[i]=LOW[i]=++Index;
	instack[i]=true;
	top++;
	Stack[top]=i;
	for (k=head[i]; k!=-1; k=edge[k].next) {
		j=edge[k].to;
		if (!DFN[j]) {//j未访问，用dfn值标记是否已访问过
			tarjan(j);
			if (LOW[j]<LOW[i])
				LOW[i]=LOW[j];
		}
		else if (instack[j] && DFN[j]<LOW[i])
			LOW[i]=DFN[j];
	}
	if (DFN[i]==LOW[i]) {//dfn和low相等，递归打印强连通分量
		Bcnt++;//强连通分量编号
		do {
			j=Stack[top--];
			instack[j]=false;
			belong[j]=Bcnt;
		}
		while (j!=i);
	}
}
void judge() {
	for(int i=1; i<=n; i++) {
		for (int k=head[i]; k!=-1; k=edge[k].next) {
			if(belong[i]!=belong[edge[k].to]) {
				Judge[belong[i]]=false;
			}
		}
	}
}

void solve() {
	init();
	read();
	for (int i=1; i<=n; i++) {
		if (!DFN[i]) {
			tarjan(i);
		}
	}
	judge();
	int ss;
	for (int i=n; i>=1; i--) {
		if(Judge[belong[i]]) {
			ss=i;
			break;
		}
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n;
	m = n;
	for (int i = 1; i <= n; i++) {
		std::cin >> cost[i];
	}
	solve();
	std::vector<int> minn(Bcnt+1);
	std::fill(minn.begin(), minn.end(), 100000);
	for (int i = 1; i <= n; i++) {
		minn[belong[i]] = std::min(cost[i], minn[belong[i]]);
	}
	for (int i = 1; i <= n; i++) {
		if (belong[i] != belong[a[i]]) {
			in[belong[i]]++;
		}
	}
	for (int i = 0; i <= Bcnt; i++) {
		if (in[i] == 0) {
			ans+=minn[i];
		}
	}
	std::cout << ans-100000 << '\n';
}