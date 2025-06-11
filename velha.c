#include <stdio.h>
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
      // checa vitória na linha
      if (jogo[i][j] == cont_lin[1][i])
      {
        cont_lin[0][i]++;
      }
      else
      {
        cont_lin[0][i] = 0;
        cont_lin[1][i]= jogo[i][j];
      }

      if (cont_lin[0][i] == 2 && cont_lin[1][i] != 0)
        return cont_lin[1][i];


      // checa vitória na coluna
      if (jogo[i][j] == cont_col[0][j])
      {
        cont_col[1][j]++;
      }
      else {
        cont_col[1][j] = 0; // refatoração dos índices
        cont_col[0][j] = jogo[i][j];
      }

      if (cont_col[1][j] == 2 && cont_col[0][j])
        return cont_col[0][j];


      // checa vitória na diagonal principal
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
      
      // checa vitória da diagonal secundária
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
 
      if (cont_diag[0][0] == 2 && cont_diag[1][0] != 0)
        return cont_diag[1][0];
      else if (cont_diag[0][1] == 2 && cont_diag[1][1] != 0)
        return cont_diag[1][1];
    }
  }

  // refatoração: checagem de vitória fora do loop


  return -1;
}

