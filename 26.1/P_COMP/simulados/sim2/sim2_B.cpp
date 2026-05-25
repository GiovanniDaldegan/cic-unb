#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main() {
  int n, voter_count = 0;
  cin >> n;
  vector<int> votes (n);
  priority_queue<pii> rank;
  
  for (int i = 0; i < n; i++) {
    int voter_count;
    cin >> voter_count;
    votes[i] = voter_count;
    rank.push(make_pair(voter_count, i));
  }
    
  while (rank.top().second != 0) {
    pll top = rank.top();
    
    votes[0] += 1;
    votes[top.second] -= 1;
    rank.pop();
    rank.push(make_pair(votes[top.second], top.second));
    rank.push(make_pair(votes[0], 0));
    voter_count++;
  }
  
  cout << voter_count << '\n';

  return 0;
}
