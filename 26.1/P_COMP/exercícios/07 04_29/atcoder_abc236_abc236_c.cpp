// https://atcoder.jp/contests/abc236/tasks/abc236_c
// atcoder abc236_c - Route Map

#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n, m;
  cin >> n >> m;
  set<string> express;
  vector<string> names (n);

  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }
  
  for (int i = 0; i < m; i++) {
    string aux;
    cin >> aux;
    
    express.insert(aux);
  }
  
  for (int i = 0; i < n; i++) {
    express.count(names[i])
      ? cout << "Yes\n"
      : cout << "No\n";
  }

  return 0;
}