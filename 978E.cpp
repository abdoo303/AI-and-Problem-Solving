#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, w;
   cin >> n >> w;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   int count = 0;
   for (int passengers = 0; passengers <= w; passengers++) {
     bool possible = true;
     for (int i = 0; i < n; i++) {
       if (passengers + a[i] < 0 || passengers + a[i] > w) {
         possible = false;
         break;
       }
     }
     if (possible) {
       count++;
     }
   }
   cout << count << endl;
   return 0;
 }
