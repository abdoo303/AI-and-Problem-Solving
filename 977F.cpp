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
   int max_len = 1;
   vector<int> max_subseq;
   for (int i = 0; i < n; i++) {
     int cur_len = 1;
     vector<int> cur_subseq;
     for (int j = i + 1; j < n; j++) {
       if (a[j] == a[j - 1] + 1) {
         cur_len++;
         cur_subseq.push_back(j);
       } else {
         break;
       }
     }
     if (cur_len > max_len) {
       max_len = cur_len;
       max_subseq = cur_subseq;
     }
   }
   cout << max_len << endl;
   for (int i : max_subseq) {
     cout << i + 1 << " ";
   }
   return 0;
 }
