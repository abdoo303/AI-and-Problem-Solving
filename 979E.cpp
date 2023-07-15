#include <iostream>
 #include <vector>
 using namespace std;
 long long mod = 1000000007;
 int main() {
   int n, p;
   cin >> n >> p;
   vector<int> c(n);
   for (int i = 0; i < n; i++) {
     cin >> c[i];
   }
   long long ans = 0;
   for (int i = 0; i < (1 << n); i++) {
     int black = 0, white = 0;
     for (int j = 0; j < n; j++) {
       if ((i >> j) & 1) {
         if (c[j] == -1) {
           black++;
         } else {
           white++;
         }
       }
     }
     if (black % 2 == p) {
       int score = 0;
       for (int j = 0; j < n; j++) {
         for (int k = j + 1; k < n; k++) {
           if ((i >> j) & 1 && (i >> k) & 1) {
             if (c[j] != c[k]) {
               score++;
             }
           }
         }
       }
       ans = (ans + score) % mod;
     }
   }
   cout << ans << endl;
   return 0;
 }
