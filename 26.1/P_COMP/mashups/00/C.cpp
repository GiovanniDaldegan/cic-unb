// https://codeforces.com/group/oU854jcGqI/contest/679584/problem/C
// codeforces grp oU854jcGqI 679584 C - String Task

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string w; cin >> w;
  vector<int> vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
  
  for (auto c : w) {
    bool in = false;
    for (auto v : vowels) {
      if (v == (int) c +32 || v == (int) c)
        in = true;
        //cout << '.' << c;
    }

    if (!in) {
      cout << '.';

      if ((int) c <= 90)
        cout << (char) (((int) c) +32);
      else
        cout << c;
    }
  }
  cout << endl;
}
