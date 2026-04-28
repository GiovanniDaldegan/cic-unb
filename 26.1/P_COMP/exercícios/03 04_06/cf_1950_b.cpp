// https://codeforces.com/problemset/problem/1950/B
// codeforces 1950 B - Upscaling

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    int count_row = 0, count_line = 0,
        count_alt_row = 0, count_alt_line = 0;
    char simb = '#';
    
    for (int j = 0; j < 2*n; j++) {
      for (int k = 0; k < 2*n; k++) {
        if (count_row == 2) {
          count_row = 0;
          
          if (count_alt_row % 2 == 1 && count_row == 0) { // (count_line != 2) {
            simb = (simb == '#') ? '.' : '#';
            count_alt_row ++;
          }
          else
            count_line = 0;
        }
        
        cout << simb;
        count_row ++;
        count_alt_row = 0;
      }
      
      /*
      if (count_line == 2) {
        simb = (simb == '#') ? '.' : '#';
      }*/
      
      cout << '\n';
      count_line ++;
    }
  }

  return 0;
}