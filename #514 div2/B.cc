#include <iostream>
#include <string>
const int maxn=1234;
const int dx[]={1,1,1,0,0,-1,-1,-1},dy[]={-1,0,1,-1,1,-1,0,1};
int n, m;
char s[maxn][maxn];
int check(int x,int y) {
	if(x<=1||x>=n||y<=1||y>=m)
		return 0;
	for(int i=0;i<8;i++)
		if(s[x+dx[i]][y+dy[i]]!='#')
			return 0;
	return 1;
}
int main() {
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='#') {
				int flag=0;
				for(int k=0;k<8;k++)
					flag|=check(i+dx[k],j+dy[k]);
				if(!flag) {
					std::cout << "No\n";
					exit(0);
				}
			}
		}
	}
	std::cout << "Yes\n";
}