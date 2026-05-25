#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

void print_vec_int(vector<int> vec) {
  for (int i : vec) cout << i << ' ';
  cout << '\n';
}

int main() {
  int t, n;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    map<string, vector<int>> word_count; // word [players]
    string word;
    vector<string> words;
    
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < n; j++) {
        cin >> word;
        if (!word_count.count(word)) words.push_back(word);
        
        if (!word_count.count(word))
          word_count[word] = vector<int> (1,k);
        else
          word_count[word].push_back(k);
          
        //print_vec_int(word_count[word]);
      }
    }
    
    vector<int> points (3, 0);
    
    for (int j = 0; j < words.size(); j++) {
      for (int c : word_count[words[j]])
        if (word_count[words[j]].size() == 1)
          points[c] += 3;
        else if (word_count[words[j]].size() == 2)
          points[c] ++;
    }
    
    for (int j = 0; j < points.size(); j++) {
      cout << points[j] << ' ';
    }
    cout << '\n';
  }
}
