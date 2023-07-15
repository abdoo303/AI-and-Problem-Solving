#include <iostream>
 #include <vector>
 using namespace std;
 vector<int> a;
 int gcd(int x, int y) {
   if (x < y) {
     swap(x, y);
   }
   while (y > 0) {
     int tmp = x % y;
     x = y;
     y = tmp;
   }
   return x;
 }
 int main() {
   int q;
   cin >> q;
   a.push_back(0);
   for (int i = 0; i < q; i++) {
     int t;
     cin >> t;
     if (t == 1) {
       int u;
       cin >> u;
       a.push_back(u);
     } else {
       int x, k, s;
       cin >> x >> k >> s;
       int ans = -1;
       for (int j = 0; j < a.size(); j++) {
         if (k % gcd(x, a[j]) == 0 && x + a[j] <= s) {
           int cur = x ^ a[j];
           if (cur > ans) {
             ans = cur;
           }
         }
       }
       cout << ans << endl;
     }
   }
   return 0;
 }
