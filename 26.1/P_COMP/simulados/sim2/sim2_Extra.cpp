#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

void print_vec_int(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ' ';
  }
  cout << '\n';
}

int main() {
  int x, y, z, m, n;
  string wave;
  priority_queue<int, vector<int>, greater<int>> cupins;

  cin >> x >> y >> z >> m >> n;
  cin >> wave;

  for (int i = 0; i < n; i++) {
    switch (wave[i]) {
      case 'F':
        cupins.push(x);
      break;
      case 'A':
        cupins.push(y);
      break;
      case 'R':
        cupins.push(z);
      break;
    }
  }
  
  vector<int> capacidade = {m};
  //int start = 0;
  while (!cupins.empty()) {
    print_vec_int(capacidade);
    
    for (int i = 0; i < capacidade.size(); i++) {
      if (capacidade[i] < cupins.top()) {
        cout << i << ' ' <<  capacidade[i] << ' ' << cupins.top() << " uai\n";
        if (i == capacidade.size() -1) {
          capacidade.push_back(m - cupins.top());
          cupins.pop();
          break;
        }
      }
      else {
        //cout << capacidade[i] << ' ' << cupins.top() << '\n';
        capacidade[i] -= cupins.top();
        cupins.pop();
        break;
      }
      /*
      if (start == capacidade.size() || (i == start && capacidade[i] < x)) {
        start++;
      }
      else if (capacidade[i] < cupins.top()) {
        if (i == capacidade.size() -1) {
          capacidade.push_back(m - cupins.top());
          cupins.pop();
          break;
        }
      }
      else {
        //cout << capacidade[i] << ' ' << cupins.top() << '\n';
        capacidade[i] -= cupins.top();
        cupins.pop();
        break;
      }
      */
    }
  }
  print_vec_int(capacidade);
  
  cout << capacidade.size() << '\n';

  return 0;
}

