#include <iostream>
 #include <vector>
 using namespace std;
 struct Programmer {
   int skill;
   bool quarrel;
   int count;
 };
 int main() {
   int n, k;
   cin >> n >> k;
   vector<Programmer> programmers(n);
   for (int i = 0; i < n; i++) {
     cin >> programmers[i].skill;
     programmers[i].quarrel = false;
     programmers[i].count = 0;
   }
   for (int i = 0; i < k; i++) {
     int x, y;
     cin >> x >> y;
     programmers[x - 1].quarrel = true;
     programmers[y - 1].quarrel = true;
   }
   for (int i = 0; i < n; i++) {
     for (int j = 0; j < n; j++) {
       if (i != j && !programmers[i].quarrel && programmers[i].skill > programmers[j].skill) {
         programmers[i].count++;
       }
     }
   }
   for (int i = 0; i < n; i++) {
     cout << programmers[i].count << " ";
   }
   cout << endl;
   return 0;
 }
