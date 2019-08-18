#include <iostream>

struct Point {
	double x,y;
	Point(double a=0,double b=0){x=a;y=b;}
};

struct Line {
	double a,b,c,angle;
	Point p1,p2;
	Line(Point s,Point e) {
		a=s.y-e.y;
		b=e.x-s.x;
		c=s.x*e.y-e.x*s.y;
		p1=s;p2=e;
	}
	Line(){}
};

Point GetIntersect(Line l1, Line l2) {
	Point res;
	res.x=(l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b);
	res.y=(l1.c*l2.a-l2.c*l1.a)/(l1.a*l2.b-l2.a*l1.b);
	return res;
}

int main(int argc, char *argv[]) {  
	Point A, B;
	std::cin >> A.x >> A.y >> B.x >> B.y;
	Line AB = Line(A, B);
	int n;
	int ans = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		Line now;
		std::cin >> now.a >> now.b >> now.c;
		Point cross = GetIntersect(now, AB);
		if (cross.x <= std::max(A.x, B.x) && cross.x >= std::min(A.x, B.x) && cross.y <= std::max(A.y, B.y) && cross.y >= std::min(A.y, B.y)) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}