#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node{
    int alice, bob;
	Node(int a,int b){
		alice = a;
		bob = b;
	}
};

vector <Node> tree;
	
int main(int argc, char *argv[]) {
	int n,s,t;
	int colour[100010],f[100010];
	memset(f,0,sizeof(f));
	cin >> n;
	for(int i = 0;i < n-1;i++){
		cin >> s >> t;
		tree.push_back(Node(s-1,t-1));
	}
	for(int i = 0;i < n;i++){
		cin >> colour[i];
	}
	int cnt = 0;
	for(int i = 0;i < n-1;i++){
		if(colour[tree[i].alice] != colour[tree[i].bob]){
			cnt++;
			f[tree[i].alice]++;
			f[tree[i].bob]++;
		}
	}
	for(int i = 0;i < n;i++){
		if(f[i]==cnt){
			cout << "YES" << endl;
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}