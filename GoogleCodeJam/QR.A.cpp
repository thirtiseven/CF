#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char *argv[]) {
	ofstream fout ("A-out.txt"); 
	ifstream fin ("A-large.in.txt"); 
	//ifstream fin ("NO.txt");   
	
	int n;
	fin >> n;
	
	for(int time = 1;time <= n;time++){
		int re;
		char pan[10000];
		int cnt = 0;
		bool imp = false;
		fin >> pan;
		fin >> re;
		for(int i = 0;i <= strlen(pan)-re;i++){
			if(pan[i] == '-'){
				for(int j = i;j < i+re;j++){
					if(pan[j] == '+'){
						pan[j] = '-';
					}else{
						pan[j] = '+';
					}
				}
				cnt++;
			}
		}
		for(int i = 0;i < strlen(pan);i++){
			if(pan[i]=='-'){
				imp = true;
				fout << "Case #" << time <<": IMPOSSIBLE" <<endl;
				break;
			}
		}
		if(!imp){
			fout << "Case #" << time << ": " << cnt << endl;
		}
		cnt = 0;
		imp = false;
	}
}