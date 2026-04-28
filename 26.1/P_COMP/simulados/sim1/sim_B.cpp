// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/B
// codeforces grp oU854jcGqI 634521 B - Os Números de Saldanha

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll x, y, z, w;
  vector<int> nums (4);
  for (int i = 0; i < 4; i++) {
    cin >> nums[i];
  }
  
  sort(nums.begin(), nums.end());
  
  cout << nums[3] - nums[2] << ' ' << nums[3] - nums[1] << ' ' << nums[3] - nums[0] << '\n';
}

