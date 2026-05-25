// https://codeforces.com/group/oU854jcGqI/contest/689486/problem/D
// codeforces grp oU854jcGqI 689486 D - The Two Routes

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> graph (n);
  int a, b;
  
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
  }
  
  vector<pair<bool, bool>> visited (n, make_pair(false, false));
  
  bool done = false;
  
  while (!done) {
    // ônibus percorre cidades sem ferrovia
    for (int i = 0; i < n; i++) {
      // se não há ferrovia entre a cidade atual e i,
      for (int j = 0; j < graph[i].size(); j++) {
        if ()
      }
    }
  }
  
  return 0;
}
