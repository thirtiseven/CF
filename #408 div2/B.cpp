#include <iostream>
#include <set>

using namespace std;
int main(int argc, char *argv[]) {
	set<int> hole;
	int n,m,k,temp;
	cin >> n >> m >>k;
	for(int i = 0;i < m;i++){
		cin >> temp;
		hole.insert(temp);
	}
	int pos = 1;
	int a,b;
	bool useless = false;
	if(hole.count(pos)==1){
		useless = true;
	}
	for(int i = 0;i < k;i++){
		cin >> a >> b;
		if(useless){
			continue;
		}
		if(a!=pos&&b!=pos){
			continue;
		}else if(a == pos){
			pos = b;
		}else{
			pos = a;
		}
		if(hole.count(pos)==1){
			useless = true;
		}
	}
	cout << pos << endl;
}