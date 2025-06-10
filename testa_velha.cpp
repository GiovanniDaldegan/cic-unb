/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */

#define CATCH_CONFIG_MAIN
#include <stdio.h>
#include "catch.hpp"
#include "velha.h"

int jogo_vazio[3][3] = {{0, 0, 0},
                        {0, 0, 0},
                        {0, 0, 0}};

void inicia_jogo(int jogo[3][3])
{
  memcpy(jogo, jogo_vazio, sizeof(int) * 3 * 3);
}

void insere_movimento(int jogo[3][3], int lin, int col, int jogador)
{
  if (lin >=0 && lin < 3 && col >= 0 && col < 3)
    jogo[lin][col] = jogador;
}


/* TESTES */

TEST_CASE("Jogo vazio")
{
  REQUIRE(verifica_velha(jogo_vazio) == -1);
}

TEST_CASE("1 movimento válido")
{
  int jogo[3][3];
  inicia_jogo(jogo);

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
  int jogo[3][3];
  inicia_jogo(jogo);

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

TEST_CASE("2 movimentos válidos")
{
  int jogo[3][3];
  inicia_jogo(jogo);

  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 2);
  REQUIRE(verifica_velha(jogo) == -1);

  inicia_jogo(jogo);
  insere_movimento(jogo, 1, 0, 1);
  insere_movimento(jogo, 0, 0, 2);
  REQUIRE(verifica_velha(jogo) == -1);

  inicia_jogo(jogo);
  insere_movimento(jogo, 2, 2, 1);
  insere_movimento(jogo, 0, 0, 2);
  REQUIRE(verifica_velha(jogo) == -1);
}

/*
TEST_CASE("1 movimento válido, n movimento inválido")
{
  int jogo[3][3] = {{1, 1, 0},
                    {0, 0, 0},
                    {0, 0, 0}};
  REQUIRE(verifica_velha() == -2);

  jogo = {{1, 0, 0},
          {0, 0, 1},
          {0, 0, 0}};
}
*/
