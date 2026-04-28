// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/A
// codeforces grp oU854jcGqI 634521 A - Variando Strings

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    
    if (str.length() == 1) {
      cout << "yes\n";
    }
    else {
      sort(str.begin(), str.end());
      
      bool fail = false;
      string::iterator it = str.begin();
      
      while (it != str.end() -1 && !fail) {
        if (*(it +1) - *it != 1) {
          cout << "no\n";
          fail = true;
        }
        
        it ++;
      }
      
      if (!fail)
        cout << "yes\n";
    }
  }
}

