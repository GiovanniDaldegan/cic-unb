// https://codeforces.com/group/oU854jcGqI/contest/679584/problem/D
// codeforces grp oU854jcGqI 679584 D - Taxi

#include <iostream>
using namespace std;

int main() {
  int n;
  int total = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    total += s;
  }
  
  cout << total / 4 + (total % 4 != 0) << endl;
}
