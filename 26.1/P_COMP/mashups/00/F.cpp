// https://codeforces.com/group/oU854jcGqI/contest/679584/problem/F
// codeforces grp oU854jcGqI 679584 F - Prime Matrix

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long num) {
  if (num == 1)
    return false;
  else {
    for (long long i = 2; i*i <= num; i++) {
      if (num % i == 0)
        return false;
    }
    
    return true;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  vector<long> total_op_column (m, 0);
  long long entry, min_op_row = 40536, min_op_column = 40536;
  
  for (int i = 0; i < n; i++) {
    int total_op_row = 0;
    
    for (int j = 0; j < m; j++) {
      cin >> entry;
      
      if (!isPrime(entry)) {
        int op_count = 1;
        while (!isPrime(entry + op_count))
          op_count++;

        total_op_row += op_count;
        total_op_column[j] += op_count;
      }
    }
    
    if (total_op_row < min_op_row)
      min_op_row = total_op_row;
  }
  
  min_op_column = *min_element(total_op_column.begin(), total_op_column.end());
  
  min_op_row < min_op_column
    ? cout << min_op_row << endl
    : cout << min_op_column << endl;
}
