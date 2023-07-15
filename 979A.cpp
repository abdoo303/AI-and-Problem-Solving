#include <iostream>
 using namespace std;
 int main() {
   int n;
   cin >> n;
   int cuts = 0;
   for (int i = 2; i <= n + 1; i++) {
     cuts += (i - 1);
   }
   cout << cuts << endl;
   return 0;
 }
