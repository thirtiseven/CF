#include <iostream>
#include <algorithm>
#include <cmath>
#define maxn 500010
#define inf 0x7f7f7f7f

struct chess{
	char type;
	int x, y;
};

int main(int argc, char *argv[]) {  
	int n, x0, y0;
	std::cin >> n >> x0 >> y0;
	chess wn, nn, ne, ww, ee, ws, ss, se;
	int min[12], vis[12];
	for(int i = 0; i <= 10; i++) {
		min[i] = inf;
		vis[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		char temp_type;
		int tx, ty;
		std::cin >> temp_type >> tx >> ty;
		if(tx == x0) {
			if(ty < y0 && y0 - ty < min[7]) {
				min[7] = y0 - ty;
				vis[7] = 1;
				ss.type = temp_type;
				ss.x = tx;
				ss.y = ty;	
			} else if(ty > y0 && ty - y0 < min[2]) {
				min[2] = ty - y0;
				vis[2] = 1;
				nn.type = temp_type;
				nn.x = tx;
				nn.y = ty;
			}
		}
		if(ty == y0) {
			if(tx < x0 && x0 - tx < min[4]) {
				min[4] = x0 - tx;
				vis[4] = 1;
				ww.type = temp_type;
				ww.x = tx;
				ww.y = ty;	
			} else if(tx > x0 && tx - x0 < min[5]) {
				min[5] = tx - x0;
				vis[5] = 1;
				ee.type = temp_type;
				ee.x = tx;
				ee.y = ty;
			}
		}
		if(std::abs(ty - y0) == std::abs(tx - x0)) {
			if(tx < x0 && ty < y0 && x0 - tx < min[6]) {
				min[6] = x0 - tx;
				vis[6] = 1;
				ws.type = temp_type;
				ws.x = tx;
				ws.y = ty;	
			} else if(tx < x0 && ty > y0 && ty - y0 < min[1]) {
				min[1] = ty - y0;
				vis[1] = 1;
				wn.type = temp_type;
				wn.x = tx;
				wn.y = ty;	
			} else if(tx > x0 && ty < y0 && tx - x0 < min[8]) {
				min[8] = tx - x0 ;
				vis[8] = 1;
				se.type = temp_type;
				se.x = tx;
				se.y = ty;	
			} else if(tx > x0 && ty > y0 && ty - y0 < min[3]) {
				min[3] = ty - y0;
				vis[3] = 1;
				ne.type = temp_type;
				ne.x = tx;
				ne.y = ty;	
			}
		}
	}
	bool flag = 0;
	if(vis[1] && (wn.type == 'B' || wn.type == 'Q')) {
		flag = 1;
	}
	if(vis[3] && (ne.type == 'B' || ne.type == 'Q')) {
		flag = 1;
	}
	if(vis[6] && (ws.type == 'B' || ws.type == 'Q')) {
		flag = 1;
	}
	if(vis[8] && (se.type == 'B' || se.type == 'Q')) {
		flag = 1;
	}
	if(vis[2] && (nn.type == 'R' || nn.type == 'Q')) {
		flag = 1;
	}
	if(vis[4] && (ww.type == 'R' || ww.type == 'Q')) {
		flag = 1;
	}
	if(vis[5] && (ee.type == 'R' || ee.type == 'Q')) {
		flag = 1;
	}
	if(vis[7] && (ss.type == 'R' || ss.type == 'Q')) {
		flag = 1;
	}
	/*
	for(int i = 1; i < 9; i++) {
		std::cout << vis[i];
	}
	std::cout << '\n' << wn.type << nn.type << ne.type << ww.type << ee.type << ws.type << ss.type << se.type << std::endl;
	*/
	if(flag) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	return 0;
}