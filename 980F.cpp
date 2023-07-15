#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 struct Edge {
   int u, v;
 };
 int main() {
   int n, m;
   cin >> n >> m;
   vector<Edge> edges(m);
   for (int i = 0; i < m; i++) {
     cin >> edges[i].u >> edges[i].v;
   }
   // Find the connected components.
   vector<int> comp(n);
   int num_comps = 0;
   for (int i = 0; i < n; i++) {
     if (comp[i] == 0) {
       num_comps++;
       for (int j = i + 1; j < n; j++) {
         if (find(edges.begin(), edges.end(), {i, j}) != edges.end()) {
           comp[j] = num_comps;
         }
       }
     }
   }
   // Calculate the maximum distance from each node to a leaf.
   vector<int> max_dist(n, 0);
   for (int i = 0; i < n; i++) {
     if (comp[i] == 0) {
       continue;
     }
     int cur_dist = 0;
     for (int j = 0; j < n; j++) {
       if (comp[j] != comp[i]) {
         cur_dist = max(cur_dist, 1 + max_dist[j]);
       }
     }
     max_dist[i] = cur_dist;
   }
   // Print the results.
   for (int i = 0; i < n; i++) {
     cout << max_dist[i] << " ";
   }
   cout << endl;
   return 0;
 }
