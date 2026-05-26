// https://codeforces.com/group/oU854jcGqI/contest/693503/problem/Extra2
// codeforces grp oU854jcGqI 693503 Extra2 - Party

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int calc_node_depth(vector<int>& pointer_tree, vector<bool>& visited, int node) {
  int depth = 1;
  while (node != -1) {
    node = pointer_tree[node-1];
    depth++;
  }
  return depth;
}

int main() {
  int n, depth = 0;
  cin >> n;

  vector<int> management_trees (n), depths (n);
  vector<bool> visited (n, false);

  for (int i = 0; i < n; i++) {
    cin >> management_trees[i];
  }

  for (int i = 0; i < n; i++) {
    int depth_i = calc_node_depth(management_trees, visited, management_trees[i]);
    if (depth < depth_i)
      depth = depth_i;
  }

  cout << depth << '\n';
}

