// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/C
// codeforces grp oU854jcGqI 634521 C - Relógio e linhas

#include <bits/stdc++.h>
using namespace std;

bool between(int x, int y, int z) {
  return (x < y && x > z) || (x < z && x > y);
}

bool same_pairs(int x, int y, int z, int w) {
  return (x == z && y == w) || (x == w && y == z);
}

int main() {
  int t, a, b, c, d;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c >> d;
    
    if (
      (!between(a, c, d) && between(b, c, d)) ||
      (!between(b, c, d) && between(a, c, d)) ||
      (a == c || a == d || b == c || b == d)
    )
      cout << "yes\n";
    else
      cout << "no\n";
  }
}

