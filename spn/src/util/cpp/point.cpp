#include "../h/point.h"

using namespace std;

Point::Point() : x(0.0), y(0.0), cluster(-1), minDist(__DBL_MAX__) {}

Point::Point(double x, double y) : x(x), y(y), cluster(-1), minDist(__DBL_MAX__) {}

double Point::distance(Point p) { return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y); }

void Point::print() {
   cout << "Point: "
        << "[" << x << ", " << y << "]"
        << " Cluster: " << cluster << " minDist: " << minDist << endl;
}

double Point::getX() { return x; }
double Point::getY() { return y; }
int Point::getCluster() { return cluster; }
double Point::getMinDist() { return minDist; }

void Point::setCluster(int newCluster) { cluster = newCluster; }
void Point::setMinDist(int newMinDist) { minDist = newMinDist; }
