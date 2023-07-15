#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   // Calculate the maximum possible beauty.
   int max_beauty = 0;
   for (int i = 0; i < (1 << k); i++) {
     int cur_beauty = 0;
     for (int j = 0; j < n; j++) {
       if ((i & (1 << j)) != 0) {
         cur_beauty &= a[j];
       }
     }
     max_beauty = max(max_beauty, cur_beauty);
   }
   // Print the result.
   cout << max_beauty << endl;
   return 0;
 }
