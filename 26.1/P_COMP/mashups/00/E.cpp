// https://codeforces.com/group/oU854jcGqI/contest/679584/problem/E
// codeforces grp oU854jcGqI 679584 E - Registration System

#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> names;
  int n;
  string name;
  
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> name;
    
    if (names.count(name) == 0) {
      names[name] = 0;
      cout << "OK" << endl;
    }
    else {
      names[name] ++;
      string new_name = name + to_string(names[name]);
      names[new_name] = 0;
      cout << new_name << endl;
    }
  }
}
