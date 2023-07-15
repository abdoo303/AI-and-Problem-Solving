#include <iostream>
 #include <string>
 using namespace std;
 bool is_palindrome(const string &s) {
   int n = s.length();
   for (int i = 0; i < n / 2; i++) {
     if (s[i] != s[n - i - 1]) {
       return false;
     }
   }
   return true;
 }
 int main() {
   string s;
   cin >> s;
   int max_len = 0;
   for (int i = 0; i < s.length(); i++) {
     for (int j = i; j < s.length(); j++) {
       if (is_palindrome(s.substr(i, j - i + 1))) {
         max_len = max(max_len, j - i + 1);
       }
     }
   }
   if (max_len == 0) {
     cout << "0" << endl;
   } else {
     cout << max_len << endl;
   }
   return 0;
 }
