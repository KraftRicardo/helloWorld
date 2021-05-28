#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
using namespace std::chrono;

struct Row {
   uint64_t a; // Attribute a
   uint64_t b; // Attribute b
   uint64_t c; // Attribute c
   std::unique_ptr<Row> next; // The next 2_pointers for linking rows that have the same hash value in the hash table

   Row(uint64_t a, uint64_t b, uint64_t c, std::unique_ptr<Row>&  next) : a(a), b(b), c(c), next(move(next)) {}

   void print() const {
      cout << "ROW: a = " << a << " b = " << b << " c = " << c;
      if (next) {
         cout << " | ";
         next->print();
      }
   }
} __attribute__((aligned(32)));

struct Relation {
   Row** index; // Hash table
   uint64_t size; // Number of rows in relation
   uint64_t sizeIndex; // Size of the hash table, must be a power of two

   // Construct a relation
   Relation(uint64_t sizeIndex) : size(0), sizeIndex(sizeIndex) {
      // Check that sizeIndex is a power of two
      assert((sizeIndex & (sizeIndex - 1)) == 0);

      index = new Row*[sizeIndex];
      for(uint64_t i = 0; i < sizeIndex; i++){
         index[i] = nullptr;
      }
//      index = reinterpret_cast<Row**>(new std::vector<Row>);

   }

   // Destroy relation (free all memory)
   ~Relation() {
      for(uint64_t i = 0; i < sizeIndex; i++){
//         TODO : delete here index[i]
         delete index[i];
      }

      delete[] index;
   }

   // Insert a new row
   void insert(uint64_t a, uint64_t b, uint64_t c) {
      index[hash(a)] = new Row(a, b, c, index[hash(a)]);
      size++;
   }

   // Find a row using the index
   Row* lookup(uint64_t a) {
      Row* found = index[hash(a)];
      if (found == nullptr || found->a == a) {
         return found;
      }

      while (found->next) {
         if (found->a == a) {
            return found;
         }
         found = found->next;
      }
      if (found->a == a) {
         return found;
      }

      // cout << "Lookup miss!" << endl;
      return nullptr;
   }

   // Remove a row
   void remove(Row* row) {

      const auto position = hash(row->a);
      Row** current = &index[position];
      while (*current) {
         if (*current == row) {
            auto tmp = *current;
            *current = (*current)->next;
            delete tmp;
            size--;
            return;
         }
         current = &((*current)->next);
      }


//      Row* found = index[hash(row->a)];
//
//      if (found == row) {
//         index[hash(row->a)] = found->next;
//         size--;
//      } else {
//         while (found->next) {
//            if (found->next == row) {
//               found->next = row->next;
//               delete[] row;
//               size--;
//               return;
//            }
//            found = found->next;
//         }
//         // cout << "Could not find row, deleting nothing!";
//      }
   }

   // Computes index into hash table for attribute value a
   uint64_t hash(uint64_t a) {
      return a & (sizeIndex - 1);
   }

   void print() {
      cout << "#### HASHTABLE ####" << endl;
      for (uint64_t i = 0; i < sizeIndex; i++) {
         cout << i << ": ";
         if (index[i]) {
            index[i]->print();
         }
         cout << endl;
      }
      cout << "size = " << size << " sizeIndex = " << sizeIndex << endl;
   }
} __attribute__((aligned(32)));

//int main() {
//   uint64_t n = 40;
//   Relation R(16);
//
//   R.print();
//
//   // Random test data
//   vector<Row> v;
//   for (uint64_t i = 0; i < n; i++) {
//      v.push_back({i, i / 3, i / 7, nullptr});
//   }
//
//   cout << "\nSTART: insert\n"
//        << endl;
//
//   {
//      random_shuffle(v.begin(), v.end());
//      // Insert test data
//      auto start = high_resolution_clock::now();
//      for (Row& r : v) {
////         cout << "Insert: r.a = " << r.a << endl;
//         R.insert(r.a, r.b, r.c);
//      }
//      cout << "insert " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
//   }
//
//   R.print();
//   cout << "\nEND: insert\nSTART: lookup\n"
//        << endl;
//
//   {
//      random_shuffle(v.begin(), v.end());
//      // Lookup rows
//      auto start = high_resolution_clock::now();
//      for (Row& r : v) {
////         cout << "r.a = " << r.a << endl;
//         Row* r2 = R.lookup(r.a);
//         //         r2->print();
//         //         cout << "\nr2->a = " << r2->a << " r.a = " << r.a << endl;
//         assert(r2 && (r2->a == r.a));
//      }
//      cout << "lookup " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
//   }
//
//   R.print();
//   cout << "\nEND: lookup\nSTART: scan\n"
//        << endl;
//
//   {
//      auto start = high_resolution_clock::now();
//      // Scan all entries and add attribute a
//      uint64_t sum = 0;
//      for (uint64_t i = 0; i < R.sizeIndex; i++) {
//         Row* r = R.index[i];
//         while (r) {
//            sum += r->a;
//            r = r->next;
//         }
//      }
//      cout << "scan " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
//      assert(sum == ((n * (n - 1)) / 2));
//   }
//
//   R.print();
//   cout << "\nEND: scan\nSTART: delete\n"
//        << endl;
//
//   {
//      random_shuffle(v.begin(), v.end());
//      // Delete all entries
//      auto start = high_resolution_clock::now();
//      for (Row& r : v) {
//         Row* r2 = R.lookup(r.a);
//         assert(r2);
//         R.remove(r2);
//         assert(!R.lookup(r.a));
//      }
//      cout << "remove " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
//      // Make sure the table is empty
//      for (unsigned i = 0; i < R.sizeIndex; i++)
//         assert(R.index[i] == nullptr);
//   }
//
//   R.print();
//   cout << "\nEND: delete\nEND";
//
//   return 0;
//}

int main() {
   uint64_t n = 2500000;
   Relation R(1ull << 20);

   // Random test data
   vector<Row> v;
   for (uint64_t i = 0; i < n; i++)
      v.push_back({i, i / 3, i / 7, nullptr});

   {
      random_shuffle(v.begin(), v.end());
      // Insert test data
      auto start = high_resolution_clock::now();
      for (Row& r : v)
         R.insert(r.a, r.b, r.c);
      cout << "insert " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
   }

   {
      random_shuffle(v.begin(), v.end());
      // Lookup rows
      auto start = high_resolution_clock::now();
      for (Row& r : v) {
         Row* r2 = R.lookup(r.a);
         assert(r2 && (r2->a == r.a));
      }
      cout << "lookup " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
   }

   {
      auto start = high_resolution_clock::now();
      // Scan all entries and add attribute a
      uint64_t sum = 0;
      for (uint64_t i = 0; i < R.sizeIndex; i++) {
         Row* r = R.index[i];
         while (r) {
            sum += r->a;
            r = r->next;
         }
      }
      cout << "scan " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
      assert(sum == ((n * (n - 1)) / 2));
   }

   {
      random_shuffle(v.begin(), v.end());
      // Delete all entries
      auto start = high_resolution_clock::now();
      for (Row& r : v) {
         Row* r2 = R.lookup(r.a);
         assert(r2);
         R.remove(r2);
         assert(!R.lookup(r.a));
      }
      cout << "remove " << duration_cast<duration<double>>(high_resolution_clock::now() - start).count() << "s" << endl;
      // Make sure the table is empty
      for (unsigned i = 0; i < R.sizeIndex; i++)
         assert(R.index[i] == nullptr);
   }

   return 0;
}