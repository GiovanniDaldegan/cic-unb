// https://codeforces.com/group/btcK4I5D5f/contest/476090/problem/B
// codeforces grp btcK4I5D5f 476090 B - Boate Azul

#include <bits/stdc++.h>
#define pair<int, int> pii

using namespace std;

/*
class cmp
{
  public:
    bool operator()(pii a, pii b) {
      if (a.first < b.first)
        return true;
      return false;
    }
}
*/

bool vec_bin_search() {
  
}

int main()
{
  string line;
  cin >> line;
  //vector<int> clients (line.length());
  
  set<int> done;
  vector<int> que;
  
  for (int i = 0; i < line.length(); i++) {
    if (!done.contains(line[i])) {
      done.insert(line[i]);
      que.push_back(line[i]);
      if (!done.contains(line[i+1])) {
        done.contains(line[i+1]);
        que.push_back(line[i+1]);
      }
    }
  }
  
  for (int i = 0; i < size(que); i++) {
    cout << que[i];
  }
  cout << '\n';
  
  /*
  
  priority_queue<int, vector<int>, greater<int>> pq_min;
  
  for (int i = 0; i < line.length(); i++) {
    int l = 0, r = pq_min.size();
    bool in_queue = false;
    
    while (l <= r) {
      int pivot = (r-l) /2;
      if (line[i] < pq_min[pivot])
        r = pivot;
      else if (line[i] > pq_min[pivot])
        l = pivot;
      else
        in_queue = true;
    }
    
    if (!in_queue)
    
  }
  
  
  
  string line;
  cin >> line;
  vector<int> contemp (line.length());
  
  priority_queue<pii, vector<pii>, cmp> que;
  
  for (int i = 0; i < line.length(); i++) {
    priority_queue.push(make_pair());
  }
  
  for (int i = 0; i < line.length(); i++) {
  
    ? cout <<  << '\n'
    : cout << -1 << '\n';
  
  return 0;
  */
}