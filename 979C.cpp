#include <iostream>
 #include <vector>
 using namespace std;
 vector<int> adj;
 bool visited[100005];
 bool in_stack[100005];
 int n, x, y;
 void dfs(int u) {
   visited[u] = true;
   in_stack[u] = true;
   for (int v : adj[u]) {
     if (!visited[v]) {
       dfs(v);
     } else if (in_stack[v] && v == y) {
       // Kuro visited Flowrisa (x) and then Beetopia (y), so this pair is not allowed.
       return;
     }
   }
   in_stack[u] = false;
 }
 int main() {
   cin >> n >> x >> y;
   adj.resize(n + 1);
   for (int i = 0; i < n - 1; i++) {
     int u, v;
     cin >> u >> v;
     adj[u].push_back(v);
     adj[v].push_back(u);
   }
   int ans = 0;
   for (int i = 1; i <= n; i++) {
     if (i != x && i != y) {
       visited[i] = false;
       in_stack[i] = false;
       dfs(i);
       ans++;
     }
   }
   cout << ans << endl;
   return 0;
 }
