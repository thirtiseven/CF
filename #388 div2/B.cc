#include <iostream>
#include <cmath>

struct Point {
	double x, y;
	Point() { };
	Point(double x, double y) :x(x), y(y) { } 
	Point operator - (const Point &b) const { 
		return Point(x - b.x, y - b.y);
	}
	Point operator + (const Point &b) const { 
		return Point(x + b.x, y + b.y);
	}
	Point operator * (const double k) const { 
		return Point(k*x, k*y);
	}
	Point operator / (const double k) const { 
		return Point(x / k, y / k);
	}
	double Slope() { 
		return y / x;
	}
};

int main(int argc, char *argv[]) {  
	Point a, b, c;
	std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	std::cout << "3\n";
	std::cout << ((a-c)+(b-c)+c).x << " " << ((a-c)+(b-c)+c).y << "\n";
	std::cout << ((c-b)+(a-b)+b).x << " " << ((c-b)+(a-b)+b).y << "\n";
	std::cout << ((b-a)+(c-a)+a).x << " " << ((b-a)+(c-a)+a).y << "\n";
	return 0;
}