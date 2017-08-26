#include <bits/stdc++.h>  
#define pii pair<int, int>  
using namespace std;  
const int maxn = 1005;  
string str[maxn];  
int n, m;  
vector<pii > v;  
  
int main(){  
	ios::sync_with_stdio(false);  
	cin.tie(0);  
	cin >> n >> m;  
	for (int i=0; i<n; ++i)  
		cin >> str[i];  
	for (int i=0; i<n; ++i)  
		for (int j=0; j<m; ++j)  
			if (str[i][j] == '*')  
				v.push_back(make_pair(i, j));  
	bool ok = false;  
	for (int i=0; i<n&&!ok; ++i)  
		for (int j=0; j<m&&!ok; ++j){  
			int k;  
			for (k=0; k<v.size(); ++k)  
				if (v[k].first!=i && v[k].second!=j)  
					break;  
			if (k == v.size()){  
				cout << "YES" << endl << i+1 << " " << j+1 << endl;  
				ok = true;  
			}  
		}  
	if (!ok)  
		cout << "NO" << endl;  
	return 0;  
}  