#include "../h/kmeans.h"

using namespace std;

void testKMeans();
static vector<Point> kMeansClustering(vector<Point>* points, int iterations, int k);

int main(){
   cout << "Start" << endl;
   testKMeans();
   cout << "End" << endl;
}

void testKMeans() {
   vector<Point> points = readMall();

   vector<Point> centroids = kMeansClustering(&points, 10, 6);
   cout << "Centroids: " << endl;
   for (Point centroid : centroids) {
      centroid.print();
   }
}

/**
 * KMeans algorithm based on https://reasonabledeviations.com/2019/10/02/k-means-in-cpp/
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
   myfile.open("spn/res/tables/kmeans/Mall_customer_kmeans.csv");
   myfile << "x,y,c" << endl;

   for (Point p : *points) {
      myfile << p.getX() << "," << p.getY() << "," << p.getCluster() << endl;
   }
   myfile.close();

   return centroids;
}

static vector<Point> readMall() {
   ifstream file("spn/res/tables/download/Mall_customer.csv");
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
