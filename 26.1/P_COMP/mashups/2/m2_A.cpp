#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main() {
  int t, n, num;
  cin >> t;

  for (int j = 0; j < t; j++) {
    int max = -1;
    unordered_map<int, int> occur;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> num;

      if (occur.count(num)) {
        if (max < occur[num])
          max = occur[num];
        occur[num] = i;
      }
      else
        occur[num] = i;
    }

    cout << max +1 << '\n';
  }
  return 0;
}

