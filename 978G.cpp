#include <iostream>
 #include <vector>
 using namespace std;
 struct Exam {
   int s;
   int d;
   int c;
 };
 bool can_pass(vector<Exam> exams, int n) {
   int total_prep_time = 0;
   for (int i = 0; i < exams.size(); i++) {
     total_prep_time += exams[i].c;
   }
   int days_left = n;
   for (int i = 0; i < exams.size(); i++) {
     if (exams[i].d > days_left) {
       return false;
     }
     days_left -= max(0, exams[i].d - exams[i].s - exams[i].c);
   }
   return days_left >= 0;
 }
 int main() {
   int n, m;
   cin >> n >> m;
   vector<Exam> exams(m);
   for (int i = 0; i < m; i++) {
     cin >> exams[i].s >> exams[i].d >> exams[i].c;
   }
   if (!can_pass(exams, n)) {
     cout << -1 << endl;
     return 0;
   }
   vector<int> schedule(n);
   for (int i = 0; i < m; i++) {
     int cur_day = exams[i].s;
     while (cur_day < exams[i].d) {
       schedule[cur_day] = i + 1;
       cur_day++;
     }
   }
   for (int i = 0; i < n; i++) {
     if (schedule[i] == 0) {
       schedule[i] = m + 1;
     }
   }
   for (int i = 0; i < n; i++) {
     cout << schedule[i] << " ";
   }
   cout << endl;
   return 0;
 }
