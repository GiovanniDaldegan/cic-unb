// https://cses.fi/problemset/task/1618
// CSES 1618 - Trailing Zeros

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, take_five = 0;
  cin >> n;
  n -= n % 5;
  
  while (n >= 5) {
    float log_five = log(n) / log(5);
    long long mult_of_five = n;
    
    while (mult_of_five % 5 == 0 && mult_of_five >= 5) {
      mult_of_five /= 5;
      take_five++;
    }

    //take_five += log(n) / log(5);
    //cout << n << " " << floor(log(n) / log(5)) << endl;
    n -= 5;
  }
  
  /*
    if ((log_five - (int) log_five) == 0)
      take_five += log_five;
    else {
      while (mult_of_five % 5 == 0) {
        take_five++;
        mult_of_five /= 5;
      }
    }
  */
  
  /*
  */
  
  /*
  while (n >= 5) {
    long long mult_of_five = n;
    if (n % 5 == 0) {
      while (mult_of_five >= 5) {
        take_five++;
        mult_of_five /= 5;
      }
    }
    n--;
  }
  */
  

  cout << take_five << endl;
}
