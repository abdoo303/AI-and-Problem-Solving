#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   vector<int> unique;
   int last_occurrence = -1;
   for (int i = 0; i < n; i++) {
     if (a[i] != a[last_occurrence]) {
       unique.push_back(a[i]);
       last_occurrence = i;
     }
   }
   cout << unique.size() << endl;
   for (int i = 0; i < unique.size(); i++) {
     cout << unique[i] << " ";
   }
   return 0;
 }
