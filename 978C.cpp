#include <iostream>
 #include <vector>
 using namespace std;
 int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   vector<int> b(m);
   for (int i = 0; i < m; i++) {
     cin >> b[i];
   }
   vector<int> dormitory(m);
   vector<int> room(m);
   for (int i = 0; i < m; i++) {
     int current_room = 0;
     for (int j = 0; j < n; j++) {
       if (b[i] < current_room + a[j]) {
         dormitory[i] = j + 1;
         room[i] = b[i] - current_room;
         break;
       } else {
         current_room += a[j];
       }
     }
   }
   for (int i = 0; i < m; i++) {
     cout << dormitory[i] << " " << room[i] << endl;
   }
   return 0;
 }
