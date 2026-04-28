// https://codeforces.com/problemset/problem/282/A
// codeforces 381 A - Sereja and Dima

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, points1 = 0, points2 = 0;
  cin >> n;
  vector<int> cards (n);
  
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
  }
  
  vector<int>::iterator p1 = cards.begin();
  vector<int>::iterator p2 = cards.end() -1;
  vector<int>::iterator* p_bigger;
  
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (*p1 > *p2) {
        points1 += *p1;
        p1++;
      }
      else {
        points1 += *p2;
        p2--;
      }
    }
    else {
      if (*p1 > *p2) {
        points2 += *p1;
        p1++;
      }
      else {
        points2 += *p2;
        p2--;
      }
    }
  }
  
  /*
  for (int i = 0; i < n; i++) {
    p_bigger = *p1 > *p2 ? &p1 : &p2;
    
    if (i % 2 == 0)
      points1 += **p_bigger;
    else
      points2 += **p_bigger;

    if (p_bigger == &p1)
      p_bigger++;
    else
      p_bigger--;

  }
  */
  
  cout << points1 << ' ' << points2 << endl;
  
  return 0;
}