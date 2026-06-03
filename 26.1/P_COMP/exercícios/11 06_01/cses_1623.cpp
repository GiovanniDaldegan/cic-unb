// https://cses.fi/problemset/task/1623
// cses 1623 - Apple Division

#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void add_one(vector<int>& mask) {
  auto it = mask.end() -1;
  while (it != mask.begin() -1) {
    if (*it == 1) {
      *it = 0;
      it--;
    }
    else {
      *it = 1;
      break;
    }
  }
}
 
ll diff_sets(vector<ll> weights, vector<int> mask) {
  ll diff = 0;
  for (int i = 0; i < weights.size(); i++) {
    mask[i]
      ? diff += weights[i]
      : diff -= weights[i];
  }
  
  return abs(diff);
}
 
int main() {
  int n;
  ll p, min = 10e11;
  
  cin >> n;
  vector<ll> weights (n);
  vector<int> mask (n, 0);
  mask[n-1] = 1;
  
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }
  
  for (int i = 0; i < (2 << n); i++) {
    ll diff = diff_sets(weights, mask);
    if (min > diff)
      min = diff;
    
    add_one(mask);
    //for (int a : mask) cout << a << ' ';
    //cout << '\n';
  }
  
  cout << min << '\n';
 
  return 0;
}
