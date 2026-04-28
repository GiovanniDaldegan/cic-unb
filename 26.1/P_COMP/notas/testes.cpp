// template header
#include <bits/stdc++.h>
#define ll long long
#define FASTIO ios::sync_with_stdio(false)

using namespace std;

int main()
{
  FASTIO;
  cin.tie(NULL);
  cout.tie(NULL);
  
  map<int, int> doidera;
  
  for (int i = 0, j = 9; i < 10; i++, j--) {
    doidera[i] = j;
  }
  
  for (int i = 0; i < 10; i++) {
    cout << '('<< i << ", "<< doidera[i] << ')' << '\n';
  }

  set<int> nums_q_eu_gosto {1, 2, 3, 5, 8, 10, 1782};
  nums_q_eu_gosto.insert(9);    // 9 tbm é legal vai
  nums_q_eu_gosto.erase(1782);  // mudei de ideia

  return 0;
}