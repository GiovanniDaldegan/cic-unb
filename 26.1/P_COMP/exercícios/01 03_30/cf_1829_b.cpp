// https://codeforces.com/problemset/problem/1829/B
// codeforces 1829 B - Blank Space

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, count_blank = 0, max_blank = 0;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<int> v (n);
    
    for (int j = 0; j < n; j++) {
      cin >> v[j];
    }
    
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
      if (*it == 0)
        count_blank++;
      else
        count_blank = 0;
      
      if (count_blank > max_blank)
        max_blank = count_blank;

      i++;
    }
    
    /*
    vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), 0);
    vector<int>::iterator it2 = lower_bound(v.begin(), v.end(), 1);
    
    while (it1 != v.end() -1) {
      if (it2 - it1 > max_blank) {
        max_blank = it2 - it1;
      }
      
      it1 = lower_bound(it1 +1, v.end(), 0);
      it2 = lower_bound(it1 +1, v.end(), 1);
    }
    */
    
    /*
    while (it != v.end()) {
      if (*it == 0) {
        count_blank++;
        if (count_blank > max_blank)
          max_blank = count_blank;
        it++;
      }
      else {
        count_blank = 0;
        it = lower_bound(it +1, v.end(), 0);
        if (*it != 0)
          break;
        
        cout << *it << " " << it - v.begin() << endl;
      }
    }
    */
    
    cout << max_blank << endl;
    
    //cout << upper_bound(v.begin(), v.end(), 0) - lower_bound(v.begin(), v.end(), 0) << endl;
  }
}