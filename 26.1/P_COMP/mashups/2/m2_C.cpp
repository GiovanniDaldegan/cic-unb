// https://codeforces.com/group/oU854jcGqI/contest/693503/problem/C
// codeforces grp oU854jcGqI 693503 C - YetnotherrokenKeoard

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

void print_vec_char(vector<char> vec) {
  for (char ch : vec) {
    if (ch != ' ') cout << ch;
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    string word;
    vector<int> min, mai;
    int ignore_count = 0;
    
    cin >> word;
    vector<char> res (word.length(), ' ');
    
    for (int j = 0; j < word.length(); j++) {
      char ch = word[j];
      
      if (ch == 'b') {
        if (!min.empty()) {
          res[min.back()] = ' ';
          min.pop_back();
        }
      }
      else if (ch == 'B') {
        if (!mai.empty()) {
          res[mai.back()] = ' ';
          mai.pop_back();
        }
      }
      else {
        res[j] = ch;
        if (ch >= 'a' && ch <= 'z')
          min.push_back(j);
        else if (ch >= 'A' && ch <= 'Z')
          mai.push_back(j);
      }
    }

    print_vec_char(res);
  }
}
