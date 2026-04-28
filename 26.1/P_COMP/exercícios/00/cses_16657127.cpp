// https://cses.fi/problemset/result/16657127/
// CSES 16657127 - Missing Number

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int l = 0;
  int r = n -1;
  int missing = 0;
  
  vector<int> vec (n);
  
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  
  int pivot = r / 2;
  
  while (l < r) {
    if (pivot > vec[pivot] -1) {
      r = pivot -1;
    }
    else { // missing dps do pivot
      l = pivot +1;
    }
  }
  cout << l << endl;
}
 
/*
int main1() {
  long long int n, m, t;
  cin >> n;
  
  m = n * (n -1) /2;
  
  for (int i = 0;
  
  return 0;
}*/
