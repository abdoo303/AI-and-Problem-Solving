#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 int main() {
   int n, m;
   cin >> n;
   vector<pair<int, int>> chemforces(n);
   for (int i = 0; i < n; i++) {
     cin >> chemforces[i].first >> chemforces[i].second;
   }
   cin >> m;
   vector<pair<int, int>> topchemist(m);
   for (int i = 0; i < m; i++) {
     cin >> topchemist[i].first >> topchemist[i].second;
   }
   // Sort the elements in decreasing order of their income.
   sort(chemforces.begin(), chemforces.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });
   sort(topchemist.begin(), topchemist.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });
   // Initialize the maximum income.
   int max_income = 0;
   // Iterate over all possible combinations of elements for ChemForces.
   for (int i = 0; i <= n; i++) {
     // Iterate over all possible combinations of elements for TopChemist.
     for (int j = 0; j <= m; j++) {
       // Calculate the income for the current combination.
       int cur_income = 0;
       for (int k = 0; k < i; k++) {
         cur_income += chemforces[k].second;
       }
       for (int k = 0; k < j; k++) {
         cur_income += topchemist[k].second;
       }
       // Update the maximum income if necessary.
       max_income = max(max_income, cur_income);
     }
   }
   // Print the maximum income.
   cout << max_income << endl;
   return 0;
 }
