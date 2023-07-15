#include <iostream>
 #include <vector>
 using namespace std;
 bool is_possible(vector<int>& a) {
   for (int i = 1; i < a.size(); i++) {
     if (a[i] == 2 * a[i - 1]) {
       continue;
     } else if (a[i] == a[i - 1] / 3) {
       continue;
     } else {
       return false;
     }
   }
   return true;
 }
 void solve(vector<int>& a) {
   int n = a.size();
   for (int i = 0; i < n / 2; i++) {
     int tmp = a[i];
     a[i] = a[n - 1 - i];
     a[n - 1 - i] = tmp;
   }
 }
 int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   if (!is_possible(a)) {
     cout << "-1" << endl;
     return 0;
   }
   solve(a);
   for (int i = 0; i < n; i++) {
     cout << a[i] << " ";
   }
   cout << endl;
   return 0;
 }
