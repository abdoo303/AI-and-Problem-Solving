#include <iostream>
 #include <vector>
 using namespace std;
 bool is_valid(vector<vector<int>> &paths, int n) {
   for (int i = 0; i < n; i++) {
     for (int j = i + 1; j < n; j++) {
       if (paths[i].size() == 0 || paths[j].size() == 0) {
         continue;
       }
       bool found = false;
       for (int k = 0; k < paths[i].size(); k++) {
         for (int l = 0; l < paths[j].size(); l++) {
           if (paths[i][k] == paths[j][l]) {
             found = true;
             break;
           }
         }
         if (found) {
           break;
         }
       }
       if (!found) {
         return false;
       }
     }
   }
   return true;
 }
 int main() {
   int n;
   cin >> n;
   vector<vector<int>> paths(n);
   for (int i = 0; i < n - 1; i++) {
     int a, b;
     cin >> a >> b;
     paths[a - 1].push_back(b - 1);
     paths[b - 1].push_back(a - 1);
   }
   if (!is_valid(paths, n)) {
     cout << "No" << endl;
     return 0;
   }
   cout << "Yes" << endl;
   cout << paths.size() << endl;
   for (int i = 0; i < paths.size(); i++) {
     cout << paths[i][0] + 1 << " " << paths[i][paths[i].size() - 1] + 1 << endl;
   }
   return 0;
 }
