#include <iostream>
 #include <string>
 #include <vector>
 using namespace std;
 struct Ribbon {
   string str;
   int beauty;
   Ribbon() {}
   Ribbon(string str) {
     this->str = str;
     this->beauty = 1;
     for (int i = 0; i < str.length(); i++) {
       int count = 1;
       for (int j = i + 1; j < str.length() && str[i] == str[j]; j++) {
         count++;
       }
       this->beauty = max(this->beauty, count);
     }
   }
 };
 int main() {
   int n;
   cin >> n;
   Ribbon kuro(string(n, 'a'));
   Ribbon shiro(string(n, 'a'));
   Ribbon katie(string(n, 'a'));
   for (int i = 0; i < n; i++) {
     char c;
     cin >> c;
     kuro.str[i] = c;
     shiro.str[i] = c;
     katie.str[i] = c;
   }
   for (int i = 0; i < n; i++) {
     char c;
     cin >> c;
     if (c != kuro.str[i]) {
       kuro.str[i] = c;
       kuro.beauty = 1;
       for (int j = 0; j < n; j++) {
         int count = 1;
         for (int k = j + 1; k < n && kuro.str[j] == kuro.str[k]; k++) {
           count++;
         }
         kuro.beauty = max(kuro.beauty, count);
       }
     }
     if (c != shiro.str[i]) {
       shiro.str[i] = c;
       shiro.beauty = 1;
       for (int j = 0; j < n; j++) {
         int count = 1;
         for (int k = j + 1; k < n && shiro.str[j] == shiro.str[k]; k++) {
           count++;
         }
         shiro.beauty = max(shiro.beauty, count);
       }
     }
     if (c != katie.str[i]) {
       katie.str[i] = c;
       katie.beauty = 1;
       for (int j = 0; j < n; j++) {
         int count = 1;
         for (int k = j + 1; k < n && katie.str[j] == katie.str[k]; k++) {
           count++;
         }
         katie.beauty = max(katie.beauty, count);
       }
     }
   }
   int winner = 0;
   int max_beauty = 0;
   if (kuro.beauty > max_beauty) {
     max_beauty = kuro.beauty;
     winner = 1;
   }
   if (shiro.beauty > max_beauty) {
     max_beauty = shiro.beauty;
     winner = 2;
   }
   if (katie.beauty > max_beauty) {
     max_beauty = katie.beauty;
     winner = 3;
   }
   if (winner == 1) {
     cout << "Kuro";
   } else if (winner == 2) {
     cout << "Shiro";
   } else if (winner == 3) {
     cout << "Katie";
   } else {
     cout << "Draw";
   }
   return 0;
 }
