// https://codeforces.com/problemset/problem/282/A
// codeforces 282 A - Bit++

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x = 0;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;
    
    for (char c : op) {
      if (c == '+')
        x++;
      else if (c == '-')
        x--;
    }
  }
  
  cout << x;
  return 0;
}