#include <iostream>
 #include <vector>
 using namespace std;
 int perfect_squares(int n) {
   int count = 0;
   for (int i = 1; i * i <= n; i++) {
     count++;
   }
   return count;
 }
 int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
     cin >> a[i];
   }
   // Initialize a vector to store the number of contiguous subarrays of A that have an answer to the problem equal to k.
   vector<int> count(n + 1);
   // Iterate over all subarrays.
   for (int i = 0; i < n; i++) {
     for (int k = 1; k <= n; k++) {
       // If the product of all elements in the subarray is a perfect square, then the subarray has an answer to the problem equal to k.
       if (a[i] % k == 0 && perfect_squares(a[i] / k) == k) {
         count[k]++;
       }
     }
   }
   // Print the number of contiguous subarrays of A that have an answer to the problem equal to k for each integer k between 1 and n (inclusive).
   for (int i = 1; i <= n; i++) {
     cout << count[i] << " ";
   }
   cout << endl;
   return 0;
 }
