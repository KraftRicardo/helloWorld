#pragma once
// source: https://www.geeksforgeeks.org/strongly-connected-components/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>

class DirectedGraph {
   uint64_t numberOfVertices; // No. of vertices
   std::list<int>* edges; // An array of adjacency lists

   public:
   explicit DirectedGraph(uint64_t numberOfVertices);
   ~DirectedGraph();
   void addEdge(int v, int w);
   void print();

   DirectedGraph getTranspose();
   void fillOrder(int v, bool visited[], std::stack<int>& stack);
   void DFSUtil(int v, bool visited[]);
   void printSCCs();
};

void testGraph();