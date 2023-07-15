#include <iostream>
 #include <vector>
 using namespace std;
 bool is_possible(string s) {
   // Count the number of links and pearls.
   int num_links = 0;
   int num_pearls = 0;
   for (char c : s) {
     if (c == '-') {
       num_links++;
     } else {
       num_pearls++;
     }
   }
   // Check if the number of links between adjacent pearls can be equal.
   if (num_links % 2 == 1) {
     return false;
   }
   // Initialize a vector to store the number of links between adjacent pearls.
   vector<int> num_adjacent_links(num_pearls, 0);
   // Iterate over the string and update the number of links between adjacent pearls.
   for (int i = 0; i < s.length(); i++) {
     if (i == 0 || s[i - 1] == '-') {
       num_adjacent_links[i % num_pearls]++;
     }
   }
   // Check if the number of links between adjacent pearls is equal.
   for (int i = 0; i < num_pearls; i++) {
     if (num_adjacent_links[i] != num_links / 2) {
       return false;
     }
   }
   return true;
 }
 int main() {
   string s;
   cin >> s;
   // Print the answer.
   if (is_possible(s)) {
     cout << "YES" << endl;
   } else {
     cout << "NO" << endl;
   }
   return 0;
 }
