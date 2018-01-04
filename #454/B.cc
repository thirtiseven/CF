#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string chess[14], s;
	chess[0] = "             ";
	for(int i = 1; i <= 3; i++) {
		chess[i] = " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
	}
	chess[4] = "            ";
	for(int i = 5; i <= 7; i++) {
		chess[i] = " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
	}
	chess[8] = "            ";
	for(int i = 9; i <= 11; i++) {
		chess[i] = " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
		std::cin >> s;
		chess[i] += s;
		chess[i] += " ";
	}
	chess[12] = "            ";
	int x, y;
	std::cin >> x >> y;
	if(x>3) x++;
	if(x>7) x++;
	if(y>3) y++;
	if(y>7) y++;
//	std::cout << x << " " << y << " " << chess[x][y] << '\n';
//	for(int i = 0; i <= 12; i++) {
//		for(int j = 0; j <= 12; j++) {
//			std::cout << i << " " << j << " " << chess[i][j] << " ";
//		}
//		std::cout << '\n';
//	}
//	bool all = 0;
	if(chess[x-1][y] == ' ' && chess[x][y-1] == ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 1; i <= 3; i++) {
			for(int j = 1; j <= 3; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 1; i <= 3; i++) {
				for(int j = 1; j <= 3; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] == ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 1; i <= 3; i++) {
			for(int j = 5; j <= 7; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 1; i <= 3; i++) {
				for(int j = 5; j <= 7; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] == ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] == ' ' ) {
		bool space = 0;
		for(int i = 1; i <= 3; i++) {
			for(int j = 9; j <= 11; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 1; i <= 3; i++) {
				for(int j = 9; j <= 11; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] == ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 5; i <= 7; i++) {
			for(int j = 1; j <= 3; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 5; i <= 7; i++) {
				for(int j = 1; j <= 3; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 5; i <= 7; i++) {
			for(int j = 5; j <= 7; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 5; i <= 7; i++) {
				for(int j = 5; j <= 7; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] != ' ' &&  chess[x][y+1] == ' ' ) {
		bool space = 0;
		for(int i = 5; i <= 7; i++) {
			for(int j = 9; j <= 11; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 5; i <= 7; i++) {
				for(int j = 9; j <= 11; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] == ' ' &&  chess[x+1][y] == ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 9; i <= 11; i++) {
			for(int j = 1; j <= 3; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 9; i <= 11; i++) {
				for(int j = 1; j <= 3; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] == ' ' &&  chess[x][y+1] != ' ' ) {
		bool space = 0;
		for(int i = 9; i <= 11; i++) {
			for(int j = 5; j <= 7; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 9; i <= 11; i++) {
				for(int j = 5; j <= 7; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	} else if(chess[x-1][y] != ' ' && chess[x][y-1] != ' ' &&  chess[x+1][y] == ' ' &&  chess[x][y+1] == ' ' ) {
		bool space = 0;
		for(int i = 9; i <= 11; i++) {
			for(int j = 9; j <= 11; j++) {
				if(chess[i][j] == '.') space = 1;
			}
		}
		if(!space) {
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						if(chess[i][j] == '.') {
							std::cout << '!';
						} else {
							std::cout << chess[i][j];
						}
					}
				}
				std::cout << '\n';
			}
		} else {
			for(int i = 9; i <= 11; i++) {
				for(int j = 9; j <= 11; j++) {
					if(chess[i][j] == '.') {
						chess[i][j] = '!';
					} 
				}
			}
			for(int i = 1; i <= 11; i++) {
				if(i != 4 && i != 8) {
					for(int j = 1; j <= 11; j++) {
						std::cout << chess[i][j];
					}
				}
				std::cout << '\n';
			}
		}
	}
	return 0;
}