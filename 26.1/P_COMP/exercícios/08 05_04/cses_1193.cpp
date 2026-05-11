// https://cses.fi/problemset/task/1193
// cses 1193 - Labyrinth

#include <bits/stdc++.h>
using namespace std;

string bfs_laby(vector<string>& laby, pair<int, int> start) {
  // parte do início
  // checa vizinhos iterativamente, preferindo sempre uma direção
  // se exauriu um caminho, volta atrás e tenta outras direções
  // (forma o caminho percorrido, push quando explora um caminho e pop quando volta atrás)
  // o primeiro caminho encontrado deve ser mínimo
  // retorna string com o caminho percorrido
  cout << "ehofilhinhodepapaieh\n";
}

int main()
{
	int n, m;
	cin >> n >> m;

  char laby [n][m];
  pair<int, int> a, b;
  stack<char> path;
  bool b_visited = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      laby[i].push_back(ch);
      
      if (ch == 'A')
        a = make_pair(i, j);
      else if (ch == 'B')
        b = make_pair(i, j);
    }
  }

  for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (laby[i][j]) {
			  case '.':
  			  if (i != 0) {
  			    if () {
  			      
  			    }
  			  }
				break;
      
        case 'B':
          // AOBA (possivelmente)
        break;
        
        default:
        break;
			}

		}
	}
}