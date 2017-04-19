#include <iostream>
#include <set>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int n , m;
	cin >> n >> m;
	int k[100200];
	set<int> pal;
	set<int> mor;
	bool cancel = false;
	for(int i = 0;i < m;i++){
		cin >> k[i];
		for(int j = 0;j < k[i];j++){
			int temp;
			cin >> temp;
			pal.insert(temp);
			mor.insert(abs(temp));
		}
		if(mor.size() == pal.size()){
			cancel = true;
		}
		pal.clear();
		mor.clear();
	}
	if(cancel){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}