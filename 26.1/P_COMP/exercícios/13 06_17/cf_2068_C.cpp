#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k, count_vid = 0, count_min = 0, count_ad = 0;
    cin >> n >> k;
    vector<int> videos (n);

    for (int j = 0; j < n; j++) {
      int dur;
      cin >> dur;
      videos[j] = dur;

      //count_min += dur;
      //count_vid ++;
    }

    sort(videos.begin(), videos.end());

    auto l = videos.begin(),
         r = videos.end()-1;

    while (l <= r) {
      if (count_vid == 3 || count_min >= k) {
        count_vid = 0;
        count_min = 0;
        count_ad ++;
      }

      if (count_vid == 2) {
        count_min += *r;
        r --;
      }
      else {
        count_min += *l;
        l ++;
      }

      count_vid++;
    }

    cout << count_ad << '\n';
  }

  return 0;
}

// se count_vid < 2, vê vídeo pequeno
// se count_vid == 2 ou só tem vídeo grande, vê vídeo grande
