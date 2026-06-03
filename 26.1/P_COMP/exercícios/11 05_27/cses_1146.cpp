// https://cses.fi/problemset/task/1146
// cses 1146 - Counting Bits

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  unsigned ll n, count = 0;
  cin >> n;

  // i = 2(pos + 1)  :  tamanho do ciclo
  for (unsigned ll i = 2; (i >> 63) != 1; i = i << 1) {
    ll rem = n % i;
    ll a = (i/2) * (n / i),                     // ciclos completos
       b = (rem >= i/2 ? rem - (i/2 - 1) : 0);  // parte do último ciclo
    count += a + b;
  }

  cout << count << '\n';
  return 0;
}

// 0000101010100001
// 1, 1, 2                | 4
// 1, 2, 2, 3             | 8
// 1, 2, 2, 3, 2, 3, 3, 4 | 20
//
// 000000000 | 0
// 000000001 | 1
// 000000010 | 2
// 000000011 | 3
// 000000100 | 4
// 000000101 | 5 <-
// 000000110 | 6
// 000000111 | 7
// 000001000 | 8    n / 2 + (n % 2 if n % 2 >= 2 / 2) 
