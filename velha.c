#include "velha.h"

int verifica_velha(int jogo[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (jogo[i][j] == 2)
        return -2;
    }
  }
  
  return -1;
}

