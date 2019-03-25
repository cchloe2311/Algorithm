#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Node {
   public:
      int id;
      int weight;
      Node(int id, int weight) {
         this->id = id;
         this->weight = weight;
      }
};

int main() {
   int n, m;
   cin >> n >> m;

   // 1 to n의 그래프
   vector<Node> *graph = new vector<Node>[n];
   for (int i = 0; i < m; i++) {
       int a, b, c;
       cin >> a >> b >> c;

       graph[a].push_back(Node(b, c));
       graph[b].push_back(Node(a, c));
   }

   bool *isMin = new bool[n];
   memset(isMin, false, sizeof(bool) * (n));

   int *shortestDist = new int[n];
   fill(shortestDist, shortestDist + (n), INT_MAX);
   shortestDist[0] = 0;

   for (int i = 0; i < n; i++) {
      int minValue = INT_MAX;
      int minIdx = -1;

      for (int j = 0; j < n; j++) {
         if (!isMin[j] && (shortestDist[j] < minValue)) {
            minValue = shortestDist[j];
            minIdx = j;
         }
      }

      isMin[minIdx] = true;

      for (int j = 0; j < graph[minIdx].size(); j++) {
         int tempValue = shortestDist[minIdx] + graph[minIdx][j].weight;
         if (tempValue < shortestDist[graph[minIdx][j].id]) {
            shortestDist[graph[minIdx][j].id] = tempValue;
         }
      }
   }

   for (int i = 0; i < n; i++) {
       cout << shortestDist[i] << " ";
   }
}