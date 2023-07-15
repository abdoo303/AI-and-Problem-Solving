#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 int main() {
   int n, L;
   cin >> n >> L;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   for (int i = 0; i < n; i++) {
     cin >> b[i];
   }
   // Calculate the distances between the palaces and castles.
   vector<int> dist(n);
   for (int i = 0; i < n; i++) {
     dist[i] = abs(b[i] - a[i]);
   }
   // Find the maximum distance that a bride has to walk.
   int max_dist = 0;
   for (int i = 0; i < n; i++) {
     max_dist = max(max_dist, dist[i]);
   }
   // The smallest possible inconvenience is the maximum distance minus the shortest distance.
   int min_inconvenience = max_dist - *min_element(dist.begin(), dist.end());
   cout << min_inconvenience << endl;
   return 0;
 }
