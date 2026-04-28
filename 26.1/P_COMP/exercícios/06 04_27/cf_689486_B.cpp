// https://codeforces.com/group/oU854jcGqI/contest/689486/problem/B
// codeforces grp oU854jcGqI 689486 B - Atendimento

#include <bits/stdc++.h>
#define ll long long
#define plli pair<ll, int>

using namespace std;

int main()
{
  int n, m;
  long long max = 0;
  cin >> n >> m;
  
  vector<int> funcs (n), clients (m);
  priority_queue<plli, vector<plli>, greater<plli>> que;
  
  for (int i = 0; i < n; i++)
    cin >> funcs[i];
  for (int i = 0; i < m; i++) {
    cin >> clients[i];
    
    if (i < n) {
      que.push(make_pair(clients[i] * funcs[i], i));
      
      if (clients[i] * funcs[i] > max)
        max = clients[i] * funcs[i];
      
      //cout << i << ' ' << clients[i] * funcs[i] << '\n';
    }
    else {
      plli tmp = que.top();
      ll new_time = tmp.first + clients[i] * funcs[tmp.second];
      
      que.pop();
      que.push(make_pair(tmp.first + clients[i] * funcs[tmp.second], tmp.second));
      
      if (new_time > max)
        max = new_time;
      
      //cout << i << ' ' << tmp.second << ' ' << tmp.first << " > " << tmp.first + clients[i] * funcs[tmp.second] << '\n';
    }
  }
  
  cout << max << '\n';

  return 0;
}