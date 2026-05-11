// https://cses.fi/problemset/task/1667
// CSES 1667 - Message Route

#include <bits/stdc++.h>
using namespace std;

void print_atecessor(vector<int>& m, int start, int end, int depth) {
  int antec = m[end];
  if (end != start)
    print_atecessor(m, start, antec, depth+1);

  if (end == start)
    cout << depth << '\n';
  cout << end +1 << ' ' ;
}

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> graph (n);
  
  for (int i = 0; i < m; i++) {
    int c1, c2;
    cin >> c1 >> c2;
    
    graph[c1-1].push_back(c2-1);
    graph[c2-1].push_back(c1-1);
  }
    
  queue<int> que;
  que.push(0);
  vector<bool> visited (n, false);
  vector<int> antecessors (n, -1);

  while(que.size()) {
    int curr = que.front();
    que.pop();
    for (int v : graph[curr]) {
      if (!visited[v]) {
        que.push(v);
        visited[v] = true;
        
        antecessors[v] = curr;
      }
    }
  }
  
  if (!visited[n-1])
    cout << "IMPOSSIBLE";
  else
    print_atecessor(antecessors, 0, n-1, 1);
  cout << '\n';

  return 0;
}