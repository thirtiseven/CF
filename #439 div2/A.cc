#include <iostream>
#include <fstream>
#include <set>

#define maxn 2010

int main(int argc, char *argv[]) { 
	std::ifstream fin ("test.txt");  
	int n, x[maxn], y[maxn];
	std::set<int> sss;
	fin >> n;
	for(int i = 0; i < n; i++) {
		fin >> x[i];
		sss.insert(x[i]);
	}
	for(int i = 0; i < n; i++) {
		fin >> y[i];
		sss.insert(y[i]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int temp = x[i] ^ y[j];
			if(sss.count(temp) > 0) {
				cnt++;
			}
		}
	}
	//std::cout << cnt << std::endl;
	std::cout << (cnt%2==0?"Karen\n":"Koyomi\n");
	return 0;
}