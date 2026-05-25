#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main() {
  int n, custo = 0;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  
  int compr1, compr2;
  for (int i = 0; i < n; i++) {
    cin >> compr1;
    pq.push(compr1);
  }
  
  while (pq.size() != 1) {
    compr1 = pq.top();
    pq.pop();
    compr2 = pq.top();
    pq.pop();
    pq.push(compr1 + compr2);
    
    compr1 > compr2
      ? custo += compr1
      : custo += compr2;
  }
  
  cout << custo << '\n';

  return 0;
}

