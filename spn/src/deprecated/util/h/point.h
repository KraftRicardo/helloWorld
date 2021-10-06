#pragma once
// source: https://reasonabledeviations.com/2019/10/02/k-means-in-cpp/

#include <iostream>

class Point {
   public: // TODO change this to private after testing!
   double x;         // coordinate x
   double y;         // coordinate y
   int cluster;      // number of cluster it belongs to, -1 means no assigned
   double minDist;   // default infinite dist to nearest cluster

   public:
   Point();
   Point(double x, double y);

   double distance(Point p);
   void print();

   // getter
   double getX();
   double getY();
   int getCluster();
   double getMinDist();

   // setter
   void setCluster(int newCluster);
   void setMinDist(int newMinDist);
};