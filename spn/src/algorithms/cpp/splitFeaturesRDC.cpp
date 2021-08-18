#include "../h/splitFeaturesRDC.h"

using namespace std;

void splitFeaturesRDC(){
   cout << "Starting splitFeaturesRDC ..." << endl;

   Column c1 = Column("A", {1, 2, 3});
   Column c2 = Column("B", {5, 5, 5});
   Column c3 = Column("C", {6, 7, 8});

   Table t1 = Table("MY ABC", {c1, c2, c3});

   Column c4 = Column();

   c1.print();
   c2.print();

   t1.print();

   Table t2 = Table("Empty table", {});
}
