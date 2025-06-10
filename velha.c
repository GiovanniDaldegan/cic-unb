#include "velha.h"

int verifica_velha(int jogo[3][3])
{
  int jogadas1 = 0, jogadas2 = 0;

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


  int cont_lin = 0;
  int num_anterior_lin = 0;
  int cont_col[2][3] = {{0}};

  for (int i = 0; i < 3; i++)
  {
    cont_lin = 0; num_anterior_lin = 0;

    for (int j = 0; j < 3; j++)
    {
      // checa vitória na linha
      if (jogo[i][j] == num_anterior_lin)
      {
        cont_lin++;
      }
      else
      {
        cont_lin = 0;
        num_anterior_lin = jogo[i][j];
      }

      if (cont_lin == 2 && num_anterior_lin != 0)
        return num_anterior_lin;


      // checa vitória na coluna
      if (jogo[i][j] == cont_col[0][j])
      {
        cont_col[1][j]++;
      }
      else {
        cont_col[1][j] = 0;
        cont_col[0][j] = jogo[i][j];
      }

      if (cont_col[1][j] == 2 && cont_col[0][j])
        return cont_col[0][j];
    }
  }


  return -1;
}

