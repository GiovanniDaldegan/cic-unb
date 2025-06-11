#include <stdio.h>
#include "velha.h"

int verifica_velha(int jogo[3][3])
{
  int jogadas1 = 0, jogadas2 = 0;
  int vitorias[2] = {0};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      // números de jogador inválidos
      if (jogo[i][j] < 0 || jogo[i][j] > 2)
        return -2;

      if (jogo[i][j] == 1)
        jogadas1++;
      else if (jogo[i][j] == 2)
        jogadas2++;
    }
  }

  // número inválido de jogadas
  if (jogadas2 > jogadas1 || jogadas1 > jogadas2 + 1)
    return -2;

  // arrays de checacem de vitória
  //  [0][*] contadores de repetição (1 por linha/coluna/diagonal)
  //  [1][*] número que se repete (1 por linha/coluna/diagonal)
  //  [*][0] linha/coluna 1 ou diagonal principal
  //  [*][1] linha/coluna 2 ou diagonal secundária
  //  [*][2] linha/coluna 3
  int cont_lin[2][3] = {{0}};
  int cont_col[2][3] = {{0}};
  int cont_diag[2][2] = {{0}};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      // checa repetições nas linha
      if (jogo[i][j] == cont_lin[1][i])
      {
        cont_lin[0][i]++;
      }
      else
      {
        cont_lin[0][i] = 0;
        cont_lin[1][i]= jogo[i][j];
      }

      // checa repetições nas colunas
      if (jogo[i][j] == cont_col[1][j])
      {
        cont_col[0][j]++;
      }
      else {
        cont_col[0][j] = 0;
        cont_col[1][j] = jogo[i][j];
      }

      // checa repetições na diagonal principal
      if (i == j)
      {
        if (jogo[i][j] == cont_diag[1][0])
        {
          cont_diag[0][0]++;
        }
        else
        {
          cont_diag[0][0] = 0;
          cont_diag[1][0] = jogo[i][j];
        }
      }

      // checa repetições da diagonal secundária
      if(i + j == 2)
      {
        if (jogo[i][j] == cont_diag[1][1])
        {
          cont_diag[0][1]++;
        }
        else
        {
          cont_diag[0][1] = 0;
          cont_diag[1][1] = jogo[i][j];
        }
      }
 

      // checa vitória na linha
      if (cont_lin[0][i] == 2 && cont_lin[1][i] != 0)
        vitorias[cont_lin[1][i] - 1]++;

      // checa vitória na coluna
      if (cont_col[0][j] == 2 && cont_col[1][j])
        vitorias[cont_col[1][j] - 1]++;
   }
  }

  // checa vitória na diagonal principal
  if (cont_diag[0][0] == 2 && cont_diag[1][0] != 0)
    vitorias[cont_diag[1][0] - 1]++;
  // checa vitória na diagonal secundária
  if (cont_diag[0][1] == 2 && cont_diag[1][1] != 0)
    vitorias[cont_diag[1][1] - 1]++;

  if (vitorias[0] == 1)
    return 1;
  else if (vitorias[1] == 1)
    return 2;

  return -1;
}

