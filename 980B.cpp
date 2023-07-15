#include <iostream>
 #include <vector>
 using namespace std;
 bool is_possible(int n, int k) {
   // Check if the number of hotels is valid.
   if (k < 0 || k > 2 * (n - 2)) {
     return false;
   }
   // Initialize a vector to store the cells that have hotels.
   vector<bool> hotels(n * 4, false);
   // Iterate over all cells and try to place a hotel in each cell.
   for (int i = 0; i < n * 4; i++) {
     if (!hotels[i] && k > 0) {
       hotels[i] = true;
       k--;
     }
   }
   // Check if there are equal number of shortest paths from each village to its preferred pond.
   int num_paths_to_tuna = 0;
   int num_paths_to_salmon = 0;
   for (int i = 1; i < n * 4 - 1; i += 2) {
     if (hotels[i] && !hotels[i - 1] && !hotels[i + 1]) {
       num_paths_to_tuna++;
     } else if (hotels[i] && !hotels[i - 1] && hotels[i + 1]) {
       num_paths_to_salmon++;
     }
   }
   return num_paths_to_tuna == num_paths_to_salmon;
 }
 int main() {
   int n, k;
   cin >> n >> k;
   // Print the answer.
   if (is_possible(n, k)) {
     cout << "YES" << endl;
     for (int i = 0; i < n * 4; i++) {
       if (hotels[i]) {
         cout << "#";
       } else {
         cout << ".";
       }
     }
     cout << endl;
   } else {
     cout << "NO" << endl;
   }
   return 0;
 }
