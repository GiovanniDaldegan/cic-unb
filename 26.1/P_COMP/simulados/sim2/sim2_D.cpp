#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

bool free_pos (pii queen, pii pos) {
  return
    queen.first != pos.first &&
    queen.second != pos.second &&
    abs(queen.first - pos.first) != abs(queen.second - pos.second); 
}

 bfs(pii queen, pii king, pii ) {
  map<int, vector<int>> visited;
  
  // procurar posições adjacentes
  // atualizar posições visitadas visited[i].push(j);
  // condição de parada: chegou no objetivo ou não há caminhos livres
}

int main() {
  int n;
  cin >> n;

  while() {}
  
  
  return 0;
}


