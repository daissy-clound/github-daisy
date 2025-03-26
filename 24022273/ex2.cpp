#include <bits/stdc++.h> 
using namespace std;
class Point{
public:
    double x, y;

    Point(double a, double b) {
        x = a;
        y = b;
    }

    Point() {}

    void getPoint() {
        cin >> x >> y;
    }
};
class Line{
public: 
    double i, j, k;

    Line(Point a, Point b) {
        i = b.y - a.y; 
        j = a.x - b.x;
        k = b.x * a.y - a.x * b.y;
    }
};

int main () {
    Point A, B, C, D;
    A.getPoint();
    B.getPoint();
    C.getPoint();
    D.getPoint();
    Line d1(A, B);
    Line d2(C, D);
    
    if (abs(d1.i * d2.j - d1.j * d2.i) < 1e-9) {
        if (abs(d1.i * d2.k - d1.k * d2.i) < 1e-9) {
            cout << "MANY" << endl;
        } else {
            cout << "NO";
        }
        return 0;
    }

    double x = (-(d1.k * d2.j) + (d1.j * d2.k)) / ((d1.i * d2.j) - (d1.j * d2.i));
    double y = (-(d1.i * d2.k) + (d1.k * d2.i)) / ((d1.i * d2.j) - (d1.j * d2.i));
  
    cout << fixed << setprecision(2) << x << " " << y;
    return 0;
}