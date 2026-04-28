// https://codeforces.com/group/oU854jcGqI/contest/689486/problem/A
// codeforces grp oU854jcGqI 689486 A - Papai Noel

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for () {
    
  }
  
  list<long long> gifts;
  
  for (int i = 0; i < t; i++) {
    char op;
    long long val;
    cin >> op >> val;
    
    switch (op) {
      case 'A':
        gifts.push_back(val);
        
        if (get_max(gifts) > max)
          max = get_max(gifts);
        break;

      case 'V':
        cout << max << '\n';
        break;
        
      case 'R':
        if (!gifts.empty())
          gifts.pop_back();
        
        max = get_max(gifts);
        
        break;
    }
  }

  return 0;
}