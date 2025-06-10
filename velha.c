#include "velha.h"

int verifica_velha(int jogo[3][3])
{
  int jogadas1 = 0, jogadas2 = 0;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (jogo[i][j] == 1)
        jogadas1++;
      else if (jogo[i][j] == 2)
        jogadas2++;
    }
  }

  if (jogadas2 > jogadas1 || jogadas1 > jogadas2 + 1)
    return -2;

  return -1;
}

