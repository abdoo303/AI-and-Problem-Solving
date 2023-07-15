#include <iostream>
 #include <vector>
 using namespace std;
 const int MOD = 998244353;
 struct MagicMultiset {
   vector<int> arr;
   MagicMultiset() {
     arr.resize(1, 0);
   }
   void add(int x) {
     int cur_size = arr.size();
     while (cur_size <= x) {
       arr.push_back(0);
     }
     arr[x]++;
   }
   int sum() {
     int ans = 0;
     for (int i = 0; i < arr.size(); i++) {
       ans += arr[i];
     }
     return ans % MOD;
   }
 };
 int main() {
   int n, q;
   cin >> n >> q;
   vector<MagicMultiset> arr(n);
   for (int i = 0; i < q; i++) {
     int t, l, r, x;
     cin >> t >> l >> r;
     if (t == 1) {
       cin >> x;
       arr[l - 1].add(x);
       arr[r].add(x);
     } else {
       cout << arr[l - 1].sum() % MOD << endl;
     }
   }
   return 0;
 }
