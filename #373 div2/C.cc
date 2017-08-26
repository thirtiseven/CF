#include <iostream>
#include <string>
#include <sstream>  
#include <iomanip>

int n, k;
std::string g, beforepoint;
int flag = 0;
int start;

void dobig(int pos) {
	if(pos == -1) {
		flag = 1;
	} else {
		if(beforepoint[pos] != '9') {
			beforepoint[pos] ++;
		} else {
			beforepoint[pos] = '0';
			dobig(pos - 1);
		}
	}
}

void doit(int pos) {
	if(pos == start + 1) {
		dobig(beforepoint.length() - 1);
		g = beforepoint;
	} else {
		if(g[pos-1] != 9) {
			g[pos-1] ++;
			g.erase(pos, g.length());
		} else {
			g[pos-1] = '0';
			doit(pos - 1);
		}
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> k >> g;
	int j;
	for(int j = 0; g[j] != '.'; j++) {
		beforepoint += g[j];
	}
	start = beforepoint.length();
	while(k--) {
		int i;
		for(i = start + 1; i < g.length(); i++) {
			if(g[i] >= '5' && g[i] <= '9') {
				doit(i);
				break;
			}
		}
		if(i == g.length()-1) {
			break;
		}
	}
	if(flag) {
		std::cout << "1";
	}
	std::cout << g << std::endl;
	return 0;
}