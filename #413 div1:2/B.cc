#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > > q[4];
bool used[200001];
int p[200001],a[200001],b[200001];
int main()
{
	int n,m,c,pp;
	std::pair<int,int> t;
	std::cin >> n;
	for(int i=1;i<=n;i++)
		std::cin >> p[i];
	for(int i=1;i<=n;i++)
		std::cin >> a[i];
	for(int i=1;i<=n;i++)
		std::cin >> b[i];
	for(int i=1;i<=n;i++)
	{
		q[a[i]].push(std::make_pair(p[i],i));
		q[b[i]].push(std::make_pair(p[i],i));
	}
	std::cin >> m;
	for(int i=0;i<m;i++)
	{
		std::cin >> c;
		pp=-1;
		while(!q[c].empty())
		{
			t=q[c].top();
			q[c].pop();
			if(used[t.second])
				continue;
			else
			{
				pp=t.first;
				used[t.second]=true;
				break;
			}
		}
		std::cout << pp << " ";
	}
	std::cout << "\n";
	return 0;
}