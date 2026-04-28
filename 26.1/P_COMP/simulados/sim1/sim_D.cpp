// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/D
// codeforces grp oU854jcGqI 634521 D - Sr. Sabe-tudo

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    ll n, m, min1 = 1e6, min2 = 1e6, min12 = 3e6;
    cin >> n;
    
    for (int j = 0; j < n; j++) {
      cin >> m;
      string hab;
      cin >> hab;
      
      if (hab == "11" && m < min12) {
        min12 = m;
      }
      else {
        if (hab[0] == '1' && m < min1)
          min1 = m;
        if (hab[1] == '1' && m < min2)
          min2 = m;
      } 
    }
    
    ll sum = min1 + min2;
    if (min12 >= 1e6 && sum >= 1e6)
      cout << -1 << '\n';
    else if (min12 < sum)
      cout << min12 << '\n';
    else
      cout << sum << '\n';
  }
}

