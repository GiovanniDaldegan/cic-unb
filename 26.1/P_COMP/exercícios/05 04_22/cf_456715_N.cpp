// https://codeforces.com/group/btcK4I5D5f/contest/456715/problem/N
// codeforces grp btcK4I5D5f 456715 N - Números Balanceados

#include <bits/stdc++.h>
using namespace std;

int main()
{
  string num;
  stack<int> chrs;
  cin >> num;
  
  for (int i = 0; i < num.length(); i++) {
    if (!chrs.empty() && chrs.top() == num[i]) {
      chrs.pop();
    }
    else {
      chrs.push(num[i]);
    }
  }
  
  chrs.empty()
    ? cout << "sim"
    : cout << "nao\n";

  return 0;
}