#include<stdio.h>
#include<stack>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
stack<int>s;
vector<int>G[20005];
int pre[20005],lowlink[20005],sccno[20005],dfs_clock,scc_cnt;
int into[20005],outo[20005];
void dfs(int u){
	pre[u]=lowlink[u]=++dfs_clock;
	s.push(u);
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if (!pre[v]){
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if (!sccno[v])
			lowlink[u]=min(lowlink[u],pre[v]);
	}
	if (lowlink[u]==pre[u]){
		scc_cnt++;
		while (1){
			int v=s.top(); s.pop();
			sccno[v]=scc_cnt;
			if (v==u) break;
		}
	}
}
int main()
{
	int n,m,i,j,u,v,k1,k2,ss;
	scanf("%d%d%d",&n,&m,&ss);
		while (!s.empty()) s.pop();
		for (i=1;i<=n;i++) G[i].clear();
		for (i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		dfs_clock=scc_cnt=0;
		memset(sccno,0,sizeof(sccno));
		memset(pre,0,sizeof(pre));
		for (i=1;i<=n;i++)
			if (!pre[i]) dfs(i);
		memset(into,0,sizeof(into));
		memset(outo,0,sizeof(outo));
		for (i=1;i<=n;i++)
			for (j=0;j<G[i].size();j++)
				if (sccno[i]!=sccno[G[i][j]]){
					into[sccno[G[i][j]]]++;
					outo[sccno[i]]++;
				}
		k1=k2=0;
		for (i=1;i<=scc_cnt;i++){
			if (into[i]==0 && i != sccno[ss]) k1++;
		}
		if (scc_cnt==1) printf("0\n");
		else printf("%d\n",k1);
	return 0;
}