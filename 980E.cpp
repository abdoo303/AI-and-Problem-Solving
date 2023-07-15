#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 struct Node {
   int id;
   int fans;
   vector<int> neighbors;
 };
 void dfs(Node* node, vector<bool>& visited, vector<int>& removed) {
   visited[node->id] = true;
   removed.push_back(node->id);
   for (int neighbor : node->neighbors) {
     if (!visited[neighbor]) {
       dfs(node->neighbors[neighbor], visited, removed);
     }
   }
 }
 int main() {
   int n, k;
   cin >> n >> k;
   vector<Node> nodes(n);
   for (int i = 0; i < n - 1; i++) {
     int a, b;
     cin >> a >> b;
     nodes[a - 1].neighbors.push_back(b - 1);
     nodes[b - 1].neighbors.push_back(a - 1);
   }
   // Initialize a vector to store the visited nodes.
   vector<bool> visited(n, false);
   // Iterate over all nodes and remove the nodes that are not connected to any other nodes.
   for (int i = 0; i < n; i++) {
     if (!visited[i]) {
       dfs(&nodes[i], visited, removed);
     }
   }
   // Sort the removed nodes in increasing order.
   sort(removed.begin(), removed.end());
   // Print the removed nodes.
   for (int i = 0; i < k; i++) {
     cout << removed[i] + 1 << " ";
   }
   cout << endl;
   return 0;
 }
