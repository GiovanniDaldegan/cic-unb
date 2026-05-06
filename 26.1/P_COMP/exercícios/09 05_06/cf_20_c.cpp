// https://codeforces.com/problemset/problem/20/C
// codeforces 20 C - Dijkstra?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void print_path(map<int, int>& antecessors, int start, int end) {
  if (start != end)
    print_path(antecessors, start, antecessors[end]);
  cout << end +1 << ' ';
}

int main(){
  FASTIO

  int n, m;
  cin >> n >> m;
  
  vector<vector<pii>> graph (n);
  
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    
    a--; b--;
    
    graph[a].push_back(make_pair(w, b));
    graph[b].push_back(make_pair(w, a));
  }
  
  vector<int> d (n, 2e9);
  priority_queue<pii, vector<pii>, greater<pii>> pq; // (possible cost, node)
  pq.push(make_pair(0, 0));
  map<int, int> antecessors;
  
  while (!pq.empty()) {
    pii curr = pq.top();
    pq.pop();
    
    if (curr.first > d[curr.second])
      continue;
    
    for (pii edge : graph[curr.second]) {           // (node, weight)
      if (curr.first + edge.second < d[edge.first]) {
        d[edge.first] = curr.first + edge.second;
        pq.push(make_pair(d[edge.first], edge.first));
        antecessors[edge.first] = curr.second;
      }
    }
  }
  
  if (d[n-1] != 2e9) {
    print_path(antecessors, 0, n-1);
    cout << '\n';
  }
  else {
    cout << "-1\n";
  }

  return 0;
}