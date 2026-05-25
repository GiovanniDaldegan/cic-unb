#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, priority_queue<int, vector<int>, grater<int>>> occurs; 
  priority_queue<int> dist;

  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    
    if (!occurs.count(num)) {
      priority_queue..push(i);
    }
  }
}

