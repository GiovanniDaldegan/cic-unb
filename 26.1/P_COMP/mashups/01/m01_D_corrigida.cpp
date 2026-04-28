#include <bits/stdc++.h>
#define ll long long;
#define FASTIO ios::sync_with_stdio(false)
#define cintie cin.tie(NULL);
#define couttie cout.tie(NULL);
 
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int n, prev, curr, total = 0;
    bool liar = false;
    cin >> n;
    
    for (int j = 0; j < n; j++) {
      cin >> curr;
      total += curr;
      
      if (j > 0) {
        if (prev + curr == 0) {
          liar = true;
        }
      }
      
      prev = curr;
    }
    
    if (total >= n)
      liar = true;

    liar
      ? cout << "YES\n"
      : cout << "NO\n";
  }
}
