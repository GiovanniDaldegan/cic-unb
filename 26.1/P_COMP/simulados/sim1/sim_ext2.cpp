// https://codeforces.com/group/oU854jcGqI/contest/634521/problem/Extra2
// codeforces grp oU854jcGqI 634521 Extra2 - Negatives and Positives

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check_invert(ll a, ll b, ll c) {
  if (a + b <= -(a + b)) {
    if (b + c >= -(b + c) || -(a + b) >= -(b + c)) {
      return true;
    }
  }
  return false;
}

void print_vec(vector<ll> vec) {
  for (auto lli : vec) {
    cout << lli << ' ';
  }
  cout << '\n';
}

int main() {
  int t;
  ll n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<ll> nums (n);
    ll sum = 0;//, curr_num, prev_num, p_prev_num;
    
    for (int j = 0; j < n; j++) {
      cin >> nums[j];
      sum += nums[j];
    }

    if (n == 2 && check_invert(nums[0], nums[1], 2e10)) {
      sum += -2 * (nums[0] + nums[1]);
      print_vec(nums);
    }
    
    for (int j = 1; j < n -1; j++) {
      if (check_invert(nums[j-1], nums[j], nums[j+1])) {
        sum += -2* (nums[j-1] + nums[j]);
        nums[j-1] *= -1;
        nums[j] *= -1;
      }
      if (j == n -2) {
        if (check_invert(nums[j], nums[j+1], 2e10)) {
          sum += -2* (nums[j] + nums[j+1]);
        }
      }
      
      print_vec(nums);
      /*
      if (nums[j-1] + nums[j] < -(nums[j-1] + nums[j])) {
        if (nums[j] + nums[j+1] >= -(nums[j] + nums[j+1]) || -(nums[j-1] + nums[j]) >= -(nums[j] + nums[j+1])) {
          sum += -2* (nums[j-1] + nums[j]);
          nums[j] *= -1;
        }
      }
      
      if (j == n -2) {
        if (nums[j] + nums[j+1] < -(nums[j] + nums[j+1])) {
          sum += -2* (nums[j] + nums[j+1]);
        }
      }
      */
    }
    
    cout << sum << '\n';
    
    
    /*
    for (int j = 0; j < n; j++) {
      nums[0] = nums[1];
      nums[1] = nums[2];
      cin >> nums[2];
      
      sum += nums[2];
      
      if (j == 1 && j == n -1) {
        if (nums[1] + nums[2] < -(nums[1] + nums[2])) {
          sum += -2 * (nums[1] + nums[2]);
        }
      }
      else if (j > 1) {
        if (nums[0] + nums[1] < -(nums[0] + nums[1])) {
          if (nums[1] + nums[2] < -(nums[1] + nums[2]) && -(nums[0] + nums[1]) < -(nums[1] + nums[2])) {
            cout << nums[0] << ' ' << nums[1] << ' ' << nums[2] << " melhor " << -nums[0] << ' ' << -nums[1] << ' ' << nums[2] << '\n';
            sum += -2 * (nums[0] + nums[1]);
            nums[1] = -nums[1];
          }
        }
        
        if (j == n -1) {
          if (nums[1] + nums[2] < -(nums[1] + nums[2])) {
            sum += -2 * (nums[1] + nums[2]);
          }
        }
      }
    }
    
    cout << sum << '\n';
    */
    
    /*
    for (int j =0; j < n; j++) {
      cin >> curr_num;
      sum += curr_num;
      
      if (j == 0) {
        p_prev_num = curr_num;
      }
      else if (j == 1) {
        prev_num = curr_num;
      }
      else {
        //ll sum_prev_curr = prev_num + curr_num;
        cout << j << ": " << p_prev_num << ' ' << prev_num << ' ' <<  curr_num<< '\n';
        if (p_prev_num + prev_num < -(p_prev_num + prev_num)) {
          //if (prev_num + curr_num >= -(prev_num + curr_num) || -(prev_num + curr_num) <= -(p_prev_num + prev_num))
          
          if (prev_num + curr_num >= -(prev_num + curr_num) || -(prev_num + curr_num) <= -(p_prev_num + prev_num)) {
            sum += -2 * (p_prev_num + prev_num);
            
            p_prev_num = -prev_num;
          }
        }
        else {
          p_prev_num = prev_num;
        }
        
        prev_num = curr_num;
      }
    }
    
    cout << sum << '\n';
    */
  }
}
