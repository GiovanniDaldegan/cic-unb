// https://codeforces.com/group/oU854jcGqI/contest/679584/problem/B
// codeforces grp oU854jcGqI 679584 B - Way Too Long Words

#include <iostream>
#include <string>
using namespace std;

int main() {
  int n; cin >> n;
  
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    int l = word.length();
    if (l > 10) {
      cout << word[0];
      cout << word.length() -2;
      cout << word[word.length() -1] << "\n";
    }
    else
      cout << word << "\n";
  }
}
