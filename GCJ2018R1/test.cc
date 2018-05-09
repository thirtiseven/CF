#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		int R, C, H, V;
		std::cin >> R >> C >> H >> V;
		std::string cake[123];
		int numl[123], numc[123], tot = 0;
		memset(numl, 0, sizeof(numl));
		memset(numc, 0, sizeof(numc));
		for (int i = 0; i < R; i++) {
			std::cin >> cake[i];
			for (int j = 0; j < C; j++) {
				if (cake[i][j] == '@') {
					numl[i]++, numc[j]++, tot++;
				}
			}
		}
		if (tot == 0) {
			std::cout << "Case #" << CAS << ": POSSIBLE\n";
			continue;
		}
		if (tot%(H+1)||tot%(V+1)) {
			std::cout << "Case #" << CAS << ": IMPOSSIBLE\n";
			continue;
		}
		int piecel = tot/(H+1), piecec = tot/(V+1);
		std::vector<int> cutl;
		std::vector<int> cutc;
		cutl.push_back(0);
		cutc.push_back(0);
		bool yes = 1;
		int now = 0;
		for (int i = 0; i < R; i++) {
			if (now > piecel) {
				yes = 0;
				break;
			} else if (now == piecel) {
				now = numl[i];
				cutl.push_back(i);
			} else {
				now += numl[i];
			}
		}
		now = 0;
		for (int i = 0; i < C; i++) {
			if (now > piecec) {
				yes = 0;
				break;
			} else if (now == piecec) {
				now = numc[i];
				cutc.push_back(i);
			} else {
				now += numc[i];
			}
		}
		cutl.push_back(R);
		cutl.push_back(C);
		for (auto ii: cutl) {
			std::cout << ii << " ";
		}
		std::cout << '\n';
		for (auto ii: cutc) {
			std::cout << ii << " ";
		}
		std::cout << '\n';
		now = 0;
		for (int i = 0; i < cutl[1]; i++) {
			for (int j = 0; j < cutc[1]; j++) {
				now += int(cake[i][j] == '@');
			}
		}
		std::cout << now << '\n';
		int mi = 0;
		if (yes) {
			for (int i = 1; i < cutl.size(); i++) {
				for (int j = 1; j < cutc.size(); j++) {
					for (int aa = cutl[i-1]; aa < cutl[i]; aa++) {
						for (int bb = cutc[i-1]; bb < cutc[i]; bb++) {
							mi += (cake[aa][bb] == '@');
							std::cout << aa << " " << bb << '\n';
						}
					}
					std::cout << mi << '\n';
					if (mi != now) {
						yes = 0;
						goto out;
					}
				}
			}
		}
		out:
		if (yes) {
			std::cout << "Case #" << CAS << ": POSSIBLE\n";
		} else {
			std::cout << "Case #" << CAS << ": IMPOSSIBLE\n";
		}
	}
}