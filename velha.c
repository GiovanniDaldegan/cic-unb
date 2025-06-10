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

  for (int i = 0; i < 3; i++)
  {
    cont_lin = 0; num_anterior_lin = 0;

    for (int j = 0; j < 3; j++)
    {
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
    }
  }


  return -1;
}

