#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, k;
   cin >> n >> k;
   vector<int> colors(n);
   for (int i = 0; i < n; i++) {
     cin >> colors[i];
   }
   // Initialize a vector to store the groups.
   vector<vector<int>> groups(256);
   for (int i = 0; i < n; i++) {
     groups[colors[i]].push_back(i);
   }
   // Iterate over all groups.
   for (int i = 0; i < 256; i++) {
     if (groups[i].size() > 0) {
       // Sort the group and select the first element as the group key.
       sort(groups[i].begin(), groups[i].end());
       int key = groups[i][0];
       // Replace the colors in the group with the group key.
       for (int j = 0; j < groups[i].size(); j++) {
         colors[groups[i][j]] = key;
       }
     }
   }
   // Print the lexicographically smallest possible array that represents the image after applying the Posterization filter.
   for (int i = 0; i < n; i++) {
     cout << colors[i] << " ";
   }
   cout << endl;
   return 0;
 }
