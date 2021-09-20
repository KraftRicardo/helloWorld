#include "../h/kmeans.h"

using namespace std;

static vector<Point> kMeansClustering(vector<Point>* points, int iterations, int k);
static vector<Point> kMeansClustering2(vector<Point>* points, int epochs, int k);

void KMeans() {
   vector<Point> points = readMall();
   //   for (Point p : points) { p.print(); }

   vector<Point> centroids = kMeansClustering(&points, 10, 3);
   cout << "Centroids: " << endl;
   for (Point centroid : centroids) {
      centroid.print();
   }
}

void testKMeans() {
   vector<Point> points = readMall();

   vector<Point> centroids = kMeansClustering(&points, 5, 3);
   cout << "Centroids: " << endl;
   for (Point centroid : centroids) {
      centroid.print();
   }

   vector<Point> centroids2 = kMeansClustering2(&points, 5, 3);
   cout << "Centroids: " << endl;
   for (Point centroid : centroids2) {
      centroid.print();
   }
}

/**
 * KMeans algorithm
 *
 * @param points list of points e.g. 2 dimensional with x and y coordinate
 * @param iterations the number of iterations over which we will do our main k-means loop
 * @param k k is the number of clusters.
 * @return KMeans algorithm
 */
vector<Point> kMeansClustering(vector<Point>* points, int iterations, int k) {
   vector<Point> centroids;

   // init centroids. Take k random points of the set!
   srand(time(0)); // TODO need to set the random seed
   for (int i = 0; i < k; ++i) {
      centroids.push_back(points->at(static_cast<unsigned long>(rand()) % points->size()));
   }
   //   for (int i = 0; i < k; ++i) { centroids.push_back(points->at(i)); }
   cout << "Starting Centroids: " << endl;
   for (Point centroid : centroids) {
      centroid.print();
   }

   for (int iter = 0; iter < iterations; iter++) {
      // find cluster for each point
      for (uint64_t i = 0; i < centroids.size(); i++) {
         for (Point& p : *points) {
            double newDist = p.distance(centroids[i]);
            if (newDist < p.getMinDist()) {
               p.setMinDist(newDist);
               p.setCluster(i);
            }
         }
      }

      // init vectors used for new centroid calculation
      vector<int> nPoints;
      vector<double> sumX, sumY;
      for (int j = 0; j < k; ++j) {
         nPoints.push_back(0);
         sumX.push_back(0.0);
         sumY.push_back(0.0);
      }

      // fill them
      for (Point p : *points) {
         int clusterID = p.getCluster();
         nPoints[clusterID] += 1;
         sumX[clusterID] += p.getX();
         sumY[clusterID] += p.getY();
      }

      // calculate new centroids
      for (int j = 0; j < k; j++) {
         centroids[j] = Point(sumX[j] / nPoints[j], sumY[j] / nPoints[j]);
      }
   }

   // save calculation in new csv file
   ofstream myfile;
   myfile.open("spn/res/Mall_customer_kmeans.csv");
   myfile << "x,y,c" << endl;

   for (Point p : *points) {
      myfile << p.getX() << "," << p.getY() << "," << p.getCluster() << endl;
   }
   myfile.close();

   return centroids;
}

/**
 * Perform k-means clustering
 * @param points - pointer to vector of points
 * @param epochs - number of k means iterations
 * @param k - the number of initial centroids
 */
static vector<Point> kMeansClustering2(vector<Point>* points, int epochs, int k) {
   int n = points->size();

   // Randomly initialise centroids
   // The index of the centroid within the centroids vector
   // represents the cluster label.
   vector<Point> centroids;
   //   srand(time(0));
   //   for (int i = 0; i < k; ++i) {
   //      centroids.push_back(points->at(rand() % n));
   //   }
   for (int i = 0; i < k; ++i) {
      centroids.push_back(points->at(i));
   }
   cout << "Starting Centroids: " << endl;
   for (Point centroid : centroids) {
      centroid.print();
   }

   for (int i = 0; i < epochs; ++i) {
      // For each centroid, compute distance from centroid to each point
      // and update point's cluster if necessary
      for (vector<Point>::iterator c = begin(centroids); c != end(centroids); ++c) {
         int clusterId = c - begin(centroids);

         for (vector<Point>::iterator it = points->begin(); it != points->end(); ++it) {
            Point p = *it;
            double dist = c->distance(p);
            if (dist < p.minDist) {
               p.minDist = dist;
               p.cluster = clusterId;
            }
            *it = p;
         }
      }

      // Create vectors to keep track of data needed to compute means
      vector<int> nPoints;
      vector<double> sumX, sumY;
      for (int j = 0; j < k; ++j) {
         nPoints.push_back(0);
         sumX.push_back(0.0);
         sumY.push_back(0.0);
      }

      // Iterate over points to append data to centroids
      for (vector<Point>::iterator it = points->begin(); it != points->end(); ++it) {
         int clusterId = it->cluster;
         nPoints[clusterId] += 1;
         sumX[clusterId] += it->x;
         sumY[clusterId] += it->y;

         it->minDist = __DBL_MAX__; // reset distance
      }
      // Compute the new centroids
      for (vector<Point>::iterator c = begin(centroids); c != end(centroids); ++c) {
         int clusterId = c - begin(centroids);
         c->x = sumX[clusterId] / nPoints[clusterId];
         c->y = sumY[clusterId] / nPoints[clusterId];
      }
   }

   return centroids;

   //   // Write to csv
   //   ofstream myfile;
   //   myfile.open("output.csv");
   //   myfile << "x,y,c" << endl;
   //
   //   for (vector<Point>::iterator it = points->begin(); it != points->end();
   //        ++it) {
   //      myfile << it->x << "," << it->y << "," << it->cluster << endl;
   //   }
   //   myfile.close();
}

static vector<Point> readMall() {
   ifstream file("spn/res/Mall_customer.csv");
   if (!file.is_open()) {
      cerr << "Error: " << strerror(errno);
   }

   vector<Point> points = {};
   string line;

   //skip first line
   getline(file, line);

   while (getline(file, line)) { // do for every line
      istringstream ss(line);
      string element;
      int counter = 0;
      double x;
      double y;

      while (getline(ss, element, ',')) { // do for every element in line
         if (counter == 3) {
            x = stod(element);
            //            cout << "x: " << x << " ";
            counter++;
         } else if (counter == 4) {
            y = stod(element);
            //            cout << "y: " << y << endl;
            points.emplace_back(x, y);
            counter++;
         } else {
            counter++;
         }
      }
   }
   return points;
}
