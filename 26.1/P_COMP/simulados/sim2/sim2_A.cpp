#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;


int main() {
  ll p, n, count = 0;
  cin >> p >> n;
  stack<ll> aumentos;

  for (ll i = 0; i < n; i++) {
    ll op, z;
    cin >> op >> z;
    
    if (op == 1) {
      aumentos.push(z);
      count++;
    }
    else {
      while (z) {
        aumentos.pop();
        z--;
        count--;
      }
    }
  }
  
  while (!aumentos.empty()) {
    p += aumentos.top();
    aumentos.pop();
    count--;
  }

  cout << p << '\n';

  return 0;
}
