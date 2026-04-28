// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/Extra1
// codeforces grp oU854jcGqI 634521 Extra1 - Barca de Sushi

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int n, prev = 0, curr = 0, count1 = 0, count2 = 0, max = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> curr;
    
    if (prev == 1) {
      if (curr == 1) {
        count1++;
      }
      else {
        count2 = 1;
      }
    }
    else if (prev == 2) {
      if (curr == 2) {
        count2++;
      }
      else {
        count1 = 1;
      }
    }
    else {
      if (curr == 1)
        count1 = 1;
      else
        count2 = 1;
    }
    
    if (min(count1, count2) *2 > max)
      max = min(count1, count2) *2;
    
    prev = curr;
  }
  
  cout << max << '\n';
}
