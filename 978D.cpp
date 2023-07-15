#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n;
   cin >> n;
   vector<int> b(n);
   for (int i = 0; i < n; i++) {
     cin >> b[i];
   }
   int min_changes = n;
   for (int d = 1; d <= n; d++) {
     int changes = 0;
     int prev = b[0];
     for (int i = 1; i < n; i++) {
       int diff = b[i] - prev;
       if (diff != d && diff != -d) {
         break;
       }
       changes++;
       prev = b[i];
     }
     if (i == n) {
       min_changes = min(min_changes, changes);
     }
   }
   if (min_changes == n) {
     cout << -1 << endl;
   } else {
     cout << min_changes << endl;
   }
   return 0;
 }
