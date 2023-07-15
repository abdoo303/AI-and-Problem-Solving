#include <iostream>
 #include <string>
 using namespace std;
 int main() {
   int n;
   string filename;
   cin >> n >> filename;
   int count = 0;
   int last_x = -1;
   for (int i = 0; i < n; i++) {
     if (filename[i] == 'x') {
       if (i - last_x == 2) {
         count++;
         last_x = -1;
       } else {
         last_x = i;
       }
     }
   }
   cout << count << endl;
   return 0;
 }
