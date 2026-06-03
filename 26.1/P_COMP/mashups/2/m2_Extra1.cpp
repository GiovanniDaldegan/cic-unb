// https://codeforces.com/group/oU854jcGqI/contest/693503/problem/Extra1
// codeforces grp oU854jcGqI 693503 Extra1 - Controle Binário

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main() {
  int n, m;
  ll count = 0;
  cin >> n >> m;
  
  while (n != m) {
    if (n > (m / 2 + (m % 2)))
      n --;
    else
      n *= 2;
    
    count ++;
    cout << n << ' ' << count << '\n';
  }
  
  cout << count << '\n';
  
  // n > m /2 => subtrai
  // n <= m /2 => multiplica
}
