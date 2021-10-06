#include "../h/directedGraph.h"

using namespace std;

DirectedGraph::DirectedGraph(uint64_t numberOfVertices)
   : numberOfVertices(numberOfVertices), edges(new list<int>[numberOfVertices]) {}

DirectedGraph::~DirectedGraph() {
   delete[] edges;
}

void DirectedGraph::addEdge(int v, int w) { edges[v].push_back(w); }

void DirectedGraph::print() {
   for (auto i = 0; i < numberOfVertices; i++) {
      cout << "Vertex " << i << ": ";
      for (auto j : edges[i]) { cout << j << ", "; }
      cout << endl;
   }
}

DirectedGraph DirectedGraph::getTranspose() {
   DirectedGraph transposedGraph = DirectedGraph(numberOfVertices);

   for (uint64_t v = 0; v < numberOfVertices; v++) {
      for (int w : edges[v]) { transposedGraph.addEdge(w, v); }
   }
   return transposedGraph;
}

void DirectedGraph::DFSUtil(int v, bool* visited) {
   visited[v] = true;
   cout << v << " ";

   for (auto i : edges[v]) {
      if (!visited[i]) {
         DFSUtil(i, visited);
      }
   }
}

void DirectedGraph::fillOrder(int v, bool* visited, stack<int>& stack) {
   visited[v] = true;

   for (auto i : edges[v]) {
      if (!visited[i]) {
         fillOrder(i, visited, stack);
      }
   }
   stack.push(v);
}

// SCC = Strongly Connected Components
void DirectedGraph::printSCCs() {
   stack<int> stack;
   bool *visited = new bool[numberOfVertices];

   // Mark all the vertices as not visited (For first DFS)
   for(int i = 0; i < numberOfVertices; i++){
      visited[i] = false;
   }

   // Fill vertices in stack according to their finishing times
   for(int i = 0; i < numberOfVertices; i++){
      if(visited[i] == false){
         fillOrder(i, visited, stack);
      }
   }

   // Create a reversed graph
   DirectedGraph gT = getTranspose();

   // Mark all the vertices as not visited (For second DFS)
   for(int i = 0; i < numberOfVertices; i++){
      visited[i] = false;
   }

   // Now process all vertices in order defined by stack
   while (!stack.empty()){
      int v = stack.top();
      stack.pop();

      // Print Strongly connected component of the popped vertex
      if (!visited[v]){
         gT.DFSUtil(v, visited);
         cout << endl;
      }
   }

   delete[] visited;
}

void testGraph() {
   DirectedGraph g(5);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);

   cout << "DirectedGraph: \n";
   g.print();

   DirectedGraph gTransposed = g.getTranspose();
   cout << "Transpose: \n";
   gTransposed.print();

   cout << "SCCs: \n";
   g.printSCCs();
}