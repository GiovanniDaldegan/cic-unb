#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

void print_vec_int(vector<int> vec) {
  for (int i : vec) cout << i << ' ';
  cout << '\n';
}

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
    vector<char> res;
    vector<int> min, mai;
    int ignore_count = 0;
    
    cin >> word;
    
    for (int j = 0; j < word.length(); j++) {
      char ch = word[j];
      
      if (ch == 'b') {
        if (min.size() != 0) {
          res[min.back()-1] = ' ';
          min.pop_back();
        }
      }
      else if (ch == 'B') {
        if (mai.size() != 0) {
          res[mai.back()-1] = ' ';
          mai.pop_back();
        }
      }
      else {
        res.push_back(ch);
        if (ch >= 'a' && ch <= 'z')
          min.push_back(j);
        else if (ch >= 'A' && ch <= 'Z')
          mai.push_back(j);
      }
    }

    print_vec_char(res);
  }

}
