#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, depth = 0, ops = 0;
    cin >> n;

    for (int j = 0; j < n; j++) {
      char ch;
      cin >> ch;

      if (ch == '(')
        depth++;
      if (ch == ')') {
        if (depth > 0)
          depth--;
        else
          ops++;
      }
    }

    cout << ops << '\n';
  }


  return 0;
}

// ()())(         (()())    1
// ()()           ()()      0
// )(             ()        1
// ())()()(       (())()()  1
// )))((((())     ((((()))))3
//
// (())())(()     (())()(())
// ())((()))
