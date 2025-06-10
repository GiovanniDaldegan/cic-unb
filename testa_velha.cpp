/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.h"

TEST_CASE("Jogo vazio")
{
  int jogo[3][3] = {{0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}};

  REQUIRE(verifica_velha(jogo) == -1);
}

TEST_CASE("1 movimento válido")
{
  int jogo[3][3] = {{0}};

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      jogo[i][j] = 1;
      REQUIRE(verifica_velha(jogo) == -1);
      jogo[i][j] = 0;
    }
  }

}

TEST_CASE("1 movimento inválido")
{
  int jogo[3][3] = {{0}};

  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        jogo[i][j] = 2;
        REQUIRE(verifica_velha(jogo) == -2);
        jogo[i][j] = 0;
      }
    }
}
