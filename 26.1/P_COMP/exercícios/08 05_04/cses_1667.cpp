// https://cses.fi/problemset/task/1667
// CSES 1667 - Message Route

#include <bits/stdc++.h>
using namespace std;

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
  
  bool done = false;
  queue<int> que (1) = {0};
  vector<bool> visited (n, false);
  map<int, int> antecessor;

  while(que.size()) {
    int curr = q.front();
    q.pop();
    for (int v : q[curr]) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }

  while (que.size()) {
    for (int i = 0; i < size(grap[curr]); i++) {
      if (!visited[grap[curr][i]]) {
        que.push(grap[curr][i]);
        visited[grap[curr][i]] = true;
      }
    }
    
    // atualizar curr
  }
  
  if (!visited[n])
    cout << "IMPOSSIBLE";

  visited = {false};

  return 0;
}