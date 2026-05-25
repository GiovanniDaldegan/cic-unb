// https://cses.fi/problemset/task/1193
// cses 1193 - Labyrinth

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

void print_vec_char(vector<char> &v) {
  for (auto ch : v) {
    cout << ch;
  }
}

bool free_pos(char* laby, int* visited, pii size, pii pos) {
  return
    // (pos.first >= 0 && pos.first <= size.first -1) &&
    // (pos.second >= 0 && pos.second <= size.second -1) &&
    laby[pos.first * size.first + pos.second] != '#' &&
    !visited[pos.first * size.first + pos.second];
}

vector<char> bfs_laby(char* laby, pii &size, pii pos) {
  // setup da busca
  int visited [size.first * size.second] = {0};
  bool a_visited = false;
  //visited[pos.first * size.first + pos.second] = true;
  vector<char> path;
  string direction;
  
  cout << "start " << pos.first << ' ' << pos.second << '\n';
  int direction_checks = 0;
  
  while (true) {
    pii last_pos = pos;
    
    // checa vizinhos iterativamente, preferindo sempre uma direção
    if (pos.first > 0 && direction_checks == 0) {
      pos.first--;
      path.push_back('U');
    }
    else if (pos.second > 0 && direction_checks == 1) {
      pos.second--;
      path.push_back('L');
    }
    else if (pos.first < size.first -1 && direction_checks == 2) {
      pos.first++;
      path.push_back('D');
    }
    else if (pos.second < size.second -1 && direction_checks == 3) {
      pos.second++;
      path.push_back('R');
    }
    
    // se exauriu um caminho, volta atrás e tenta outras direções
    if (!free_pos(laby, visited, size, pos)) {
      //cout << pos.first << ' ' << pos.second << ' ' << path[path.length() -1] << '\n';
      print_vec_char(path);
      cout << '\n';
      
      switch (path.back()) {
        case 'U':
          pos.first++;
        break;
        
        case 'L':
          pos.second++;
        break;
        
        case 'D':
          pos.first--;
        break;
        
        case 'R':
          pos.second--;
        break;
      }
      
      direction_checks++;
      path.pop_back();
      
      // condição de parada caso retorne para o início
      if (laby[pos.first * size.first + pos.second] == 'A' && a_visited) {
        path.clear();
        return path;
      }

      continue;
    }
    
    if (!a_visited)
      a_visited = true;
    
    direction_checks = 0;
    visited[pos.first * size.first + pos.second] = true;
    // (forma o caminho percorrido, push quando explora um caminho e pop quando volta atrás)
    // o primeiro caminho encontrado deve ser mínimo
    // retorna string com o caminho percorrido
    if (laby[pos.first * size.first + pos.second] == 'B')
      return path;
    
    
  }
  path.clear();
  return path;
}

int main()
{
	int n, m;
	cin >> n >> m;

  char laby [n * m];
  pii size = make_pair(n, m), start;
  char ch;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      laby[i * n + j] = ch;
      
      if (ch == 'A')
        start = make_pair(i, j);
    }
  }
  cout <<"checkpoint1\n";

  vector<char> path = bfs_laby(laby, size, start);
  
  if (path.size() == 0)
    cout << "NO\n";
  else
    cout << "YES\n" << path.size() << '\n';
    print_vec_char(path);// << path << '\n';
    cout << '\n';
}