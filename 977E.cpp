#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, m;
   cin >> n >> m;
   vector<vector<int>> adj(n);
   for (int i = 0; i < m; i++) {
     int v, u;
     cin >> v >> u;
     adj[v - 1].push_back(u - 1);
     adj[u - 1].push_back(v - 1);
   }
   int count = 0;
   vector<bool> visited(n, false);
   for (int i = 0; i < n; i++) {
     if (!visited[i]) {
       int cur = i;
       visited[i] = true;
       vector<int> cycle;
       while (!visited[cur]) {
         cycle.push_back(cur);
         visited[cur] = true;
         cur = adj[cur][0];
       }
       if (cycle.size() >= 3) {
         count++;
       }
     }
   }
   cout << count << endl;
   return 0;
 }
