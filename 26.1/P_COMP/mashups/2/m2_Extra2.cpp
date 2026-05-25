#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

bool is_superior(vector<int>& sup, int a, int b) {
  bool imm = false, indir = false; 
  if (sup[b] != -1) {
    if (sup[b] == a) imm = true;  // a sup b
    
    if (sup[sup[b]] != -1) {
      if (sup.count(sup[b])) {
        if (sup[sup[b]] == a)
          indir = true;
      }
    }
  }
  
  return imm || indir;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    if ()
  }
}


//    1
//  2   3
// 4   5
// 
//     1
//    2
//   3
//  4
// 5
//

