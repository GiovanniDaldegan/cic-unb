// https://codeforces.com/contest/923/problem/B
// codeforces 923 B - Producing Snow

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, temptsum = 0, aux;
  cin >> n;

  vector<int> piles (n), tempts (n), psum (n);
 
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> aux;
    tempts[i] = aux + temptsum;
    temptsum += aux;
  }

  for (int i = 0; i < n; i++) {
    int sum = 0;

    for (int j = 0; j <= i; j++) {
      // derretido do monte j no dia i
      //  - tempt dia i, caso o monte não tenha morrido
      //  - vol monte - tempt acumulada dia i, caso o monte morra no dia i
      //  - 0, caso o monte tenha morrido antes
      
      int
        pile_j = piles[j],
        melted_i = tempts[n-1] - (i == 0 ? 0 : tempts[i-1]),
        total_melted;

      int day_that_i_die = upper_bound(tempts.begin(), tempts.end(), pile_j) - tempts.begin();

      if (day_that_i_die < i) {
        total_melted = 0;
      }
      else if (day_that_i_die == 0) {
        total_melted = pile_j - (tempts[i] - (j == 0 ? 0 : tempts[j-1]));
      }
      else {
        total_melted = tempts[i] - (i == 0 ? 0 : tempts[i-1]);
      }
      
      sum += total_melted;
    }
    cout << sum << ' ';
  }
  cout << '\n';
}


// 10 20  3 20  0  6  pilhas
//  7  2 10 24 20  5  tempts
// 10 30 33 53 53 59  pilsum
//  7  9 19 43 63 68  temptsum
//  3 21 16 12  0  1  sobra
//  7  9 10 24  0  5  derretido
