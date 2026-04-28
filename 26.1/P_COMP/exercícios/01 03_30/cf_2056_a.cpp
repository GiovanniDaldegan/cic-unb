// https://codeforces.com/problemset/problem/2056/A
// codeforces 2056 A - Shape Perimeter

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, m;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    cin >> n >> m;
    
    long long perim = 4 * m;
    int x, y;
    for (int j = 0; j < n; j++) {
      cin >> x >> y;
      
      if (j > 1)
        perim += (x + y) *2;
    }
    
    cout << perim << endl;
  }
}