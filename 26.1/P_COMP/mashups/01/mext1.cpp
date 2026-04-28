#include <bits/stdc++.h>
#define ll long long;
#define FASTIO ios::sync_with_stdio(false)
#define cintie cin.tie(NULL);
#define couttie cout.tie(NULL);
 
using namespace std;

int main() {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    
    vector<int> nums (n);
    
    for (int j = 0; j < n; j++) {
      cin >> nums[j];
    }
    
    sort(nums.begin(), nums.end());
    
    int ind1 = 0, ind2 = n -1;
    
    while (ind1 < n) {
      if ((nums[ind1] + *(nums.end() -1)) % 2 == 0)
        break;
      
      ind1++;
    }
    
    while (ind2 >= 0) { // && n - ind2 < ind1 +1
      if ((*nums.begin() + nums[ind2]) % 2 == 0)
        break;
      
      ind2--;
    }
    
    ind1 < n -1 - ind2
      ? cout << ind1 << '\n'
      : cout << n -1 - ind2 << '\n';
  }
}
