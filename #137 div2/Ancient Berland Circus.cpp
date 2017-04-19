//TODO

#include <iostream>
#include <cmath>

#define PI acos(-1.0)
#define INEXIST 1.79769e+308

using namespace std;

int main(int argc, char *argv[]) {
	double x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double xcenter,ycenter,k12,k23,kver12,kver23,xmid12,ymid12,xmid23,ymid23; 
	k12 = (x1==x2?INEXIST:(y1-y2)/(x1-x2));
	k23 = (x3==x2?INEXIST:(y3-y2)/(x3-x2));
	kver12 = - 1.0 / k12;
	kver23 = - 1.0 / k23;
	xmid12 = (x1 + x2) / 2.0;
	ymid12 = (y1 + y2) / 2.0;
	xmid23 = (x2 + x3) / 2.0;
	ymid23 = (y2 + y3) / 2.0;
	xcenter = (kver12 * xmid12 - kver23 * xmid23 + ymid23 - ymid12) / (k12 - k23);
	ycenter = k12 * (xcenter - xmid12) + ymid12;
	
	cout << k12 << ' ' << k23 << ' ' << kver12 << ' ' << kver23 << ' ' << xmid12 << ' ' << xmid23 << ' ' << ymid12 << ' ' << ymid23 << ' '<< xcenter << ' ' << ycenter << endl;
	return 0;
}