#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, q;
   cin >> n >> q;
   vector<int> a(n + 1);
   for (int i = 0; i < q; i++) {
     int l, r, x;
     cin >> l >> r >> x;
     for (int j = l; j <= r; j++) {
       a[j] += x;
     }
   }
   // Find all possible maximum values.
   vector<int> ans;
   for (int i = 1; i <= n; i++) {
     bool ok = true;
     for (int j = 0; j < q; j++) {
       if (a[i] < a[l] + x) {
         ok = false;
         break;
       }
     }
     if (ok) {
       ans.push_back(i);
     }
   }
   // Print the results.
   cout << ans.size() << endl;
   for (int i = 0; i < ans.size(); i++) {
     cout << ans[i] << " ";
   }
   cout << endl;
   return 0;
 }
