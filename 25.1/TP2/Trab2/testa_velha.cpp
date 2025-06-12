/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */


/** Insere main do catch.
 */
#define CATCH_CONFIG_MAIN

#include <stdlib.h>
#include "./catch.hpp"
#include "./velha.h"

/**
 * Array 3x3 de jogo vazio (preenchido por 0s)
 */
int jogo_vazio[3][3] = {{0}};

/** 
 * Recebe um array 3x3 de jogo da velha e preenche-o com 0s.
 * @param  jogo  Array 3x3.
 */
void inicia_jogo(int jogo[3][3]) {
  memcpy(jogo, jogo_vazio, sizeof(int) * 3 * 3);
}

/**
 * Insere um número de jogador na matriz jogo passada.
 * @param  jogo     Array 3x3.
 * @param  lin      Linha na qual inserir.
 * @param  col      Coluna na qual inserir.
 * @param  jogador  Número do jogador (1 ou 2).
 */
void insere_movimento(int jogo[3][3], int lin, int col, int jogador) {
  if (lin >=0 && lin < 3 && col >= 0 && col < 3)
    jogo[lin][col] = jogador;
}


/* TESTES */

/** TESTE 1:
 * Testa a validade de um jogo vazio, sem jogadas.
 */
TEST_CASE("Jogo vazio") {
  int jogo[3][3];
  inicia_jogo(jogo);
  REQUIRE(verifica_velha(jogo) == -1);
}

/** TESTE 2:
 * Testa todos os jogos em que só há um única jogada válida.
 */
TEST_CASE("1 movimento válido") {
  int jogo[3][3];
  inicia_jogo(jogo);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      jogo[i][j] = 1;
      REQUIRE(verifica_velha(jogo) == -1);
      jogo[i][j] = 0;
    }
  }
}

/** TESTE 3:
 * Testa todos os jogos em que só há uma jogada, feita pelo jogador 2
 * (inválido).
 */
TEST_CASE("1 movimento inválido") {
  int jogo[3][3];
  inicia_jogo(jogo);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      jogo[i][j] = 2;
      REQUIRE(verifica_velha(jogo) == -2);
      jogo[i][j] = 0;
    }
  }
}

/** TESTE 4:
 * Testa jogos com duas jogadas válidas, uma do jogador 1, outra do jogador 2.
 */
TEST_CASE("2 movimentos válidos") {
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

/** TESTE 5:
 * Testa os jogos em que a primeira jogada é válida, mas as demais não.\n
 * Exemplos: jogador 1 joga duas vezes, jogador 2 joga duas vezes.\n
 */
TEST_CASE("1 movimento valido, n movimentos inválidos") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 1);
  REQUIRE(verifica_velha(jogo) == -2);

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 1);
  insere_movimento(jogo, 0, 2, 1);
  REQUIRE(verifica_velha(jogo) == -2);

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 2);
  insere_movimento(jogo, 1, 1, 2);
  REQUIRE(verifica_velha(jogo) == -2);
}

/** TESTE 6:
 * Testa jogos em que há número de jogador inválido no quadro.\n
 * Exemplos: todo número diferente de 0, 1 e 2.
*/
TEST_CASE("Número de jogador inválido") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, -1);
  REQUIRE(verifica_velha(jogo) == -2);

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 0, 3);
  REQUIRE(verifica_velha(jogo) == -2);

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 1, 1, 2);
  insere_movimento(jogo, 2, 2, 12312312);
  REQUIRE(verifica_velha(jogo) == -2);
}

/** TESTE 7:
 * Testa casos em que um jogador vence preenchendo 3 casas na mesma linha.
 */
TEST_CASE("Jogador vence na linha") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 1 1
  insere_movimento(jogo, 0, 1, 1);  // 2 2 0
  insere_movimento(jogo, 0, 2, 1);  // 0 0 0

  insere_movimento(jogo, 1, 0, 2);
  insere_movimento(jogo, 1, 1, 2);
  REQUIRE(verifica_velha(jogo) == 1);


  inicia_jogo(jogo);
  insere_movimento(jogo, 2, 0, 1);  // 0 0 2
  insere_movimento(jogo, 2, 1, 1);  // 0 2 0
  insere_movimento(jogo, 2, 2, 1);  // 1 1 1

  insere_movimento(jogo, 0, 2, 2);
  insere_movimento(jogo, 1, 1, 2);
  REQUIRE(verifica_velha(jogo) == 1);


  inicia_jogo(jogo);
  insere_movimento(jogo, 1, 0, 2);  // 1 1 0
  insere_movimento(jogo, 1, 1, 2);  // 2 2 2
  insere_movimento(jogo, 1, 2, 2);  // 1 0 0

  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 1);
  insere_movimento(jogo, 2, 0, 1);
  REQUIRE(verifica_velha(jogo) == 2);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 1 1
  insere_movimento(jogo, 0, 1, 1);  // 1 2 2
  insere_movimento(jogo, 0, 2, 1);  // 2 0 0
  insere_movimento(jogo, 1, 0, 1);
  insere_movimento(jogo, 2, 1, 1);

  insere_movimento(jogo, 1, 1, 2);
  insere_movimento(jogo, 1, 2, 2);
  insere_movimento(jogo, 2, 0, 2);
  insere_movimento(jogo, 2, 2, 2);
  REQUIRE(verifica_velha(jogo) == 1);
}

/** TESTE 8:
 * Testa casos em que um jogador vence preenchendo 3 casas numa mesma coluna.
 */
TEST_CASE("Jogador vence na coluna") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 1, 1, 1);  // 2 1 0
  insere_movimento(jogo, 0, 1, 1);  // 0 1 0
  insere_movimento(jogo, 2, 1, 1);  // 0 1 2

  insere_movimento(jogo, 0, 0, 2);
  insere_movimento(jogo, 2, 2, 2);
  REQUIRE(verifica_velha(jogo) == 1);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 2);  // 2 1 0
  insere_movimento(jogo, 1, 0, 2);  // 2 1 1
  insere_movimento(jogo, 2, 0, 2);  // 2 0 0

  insere_movimento(jogo, 0, 1, 1);
  insere_movimento(jogo, 1, 1, 1);
  insere_movimento(jogo, 1, 2, 1);
  REQUIRE(verifica_velha(jogo) == 2);
}

/** TESTE 9:
 * Testa casos em que um jogador vence preenchendo uma diagonal.
 */
TEST_CASE("Jogador vence na diagonal") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 0 2
  insere_movimento(jogo, 1, 1, 1);  // 0 1 0
  insere_movimento(jogo, 2, 2, 1);  // 2 0 1

  insere_movimento(jogo, 2, 0, 2);
  insere_movimento(jogo, 0, 2, 2);
  REQUIRE(verifica_velha(jogo) == 1);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 2, 2);  // 1 1 2
  insere_movimento(jogo, 1, 1, 2);  // 0 2 0
  insere_movimento(jogo, 2, 0, 2);  // 2 0 1

  insere_movimento(jogo, 0, 0, 1);
  insere_movimento(jogo, 0, 1, 1);
  insere_movimento(jogo, 2, 2, 1);
  REQUIRE(verifica_velha(jogo) == 2);
}

/** TESTE 10:
 * Testa casos em que os dois jogadores marcam três casas numa linha ou coluna.
 */
TEST_CASE("Vitória dupla") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 1 1
  insere_movimento(jogo, 0, 1, 1);  // 2 2 2
  insere_movimento(jogo, 0, 2, 1);  // 0 0 0
  insere_movimento(jogo, 1, 0, 2);
  insere_movimento(jogo, 1, 1, 2);
  insere_movimento(jogo, 1, 2, 2);
  REQUIRE(verifica_velha(jogo) == -2);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 2 0
  insere_movimento(jogo, 1, 0, 1);  // 1 2 0
  insere_movimento(jogo, 2, 0, 1);  // 1 2 0
  insere_movimento(jogo, 0, 1, 2);
  insere_movimento(jogo, 1, 1, 2);
  insere_movimento(jogo, 2, 1, 2);
  REQUIRE(verifica_velha(jogo) == -2);
}

/** TESTE 11:
 * Testa jogos em que dá velha (empate).
 */
TEST_CASE("Empate") {
  int jogo[3][3];

  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 1 2
  insere_movimento(jogo, 0, 1, 1);  // 2 2 1
  insere_movimento(jogo, 0, 2, 2);  // 1 2 1
  insere_movimento(jogo, 1, 0, 2);
  insere_movimento(jogo, 1, 1, 2);
  insere_movimento(jogo, 1, 2, 1);
  insere_movimento(jogo, 2, 0, 1);
  insere_movimento(jogo, 2, 1, 2);
  insere_movimento(jogo, 2, 2, 1);
  REQUIRE(verifica_velha(jogo) == 0);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 1);  // 1 2 2
  insere_movimento(jogo, 0, 1, 2);  // 2 1 1
  insere_movimento(jogo, 0, 2, 2);  // 1 1 2
  insere_movimento(jogo, 1, 0, 2);
  insere_movimento(jogo, 1, 1, 1);
  insere_movimento(jogo, 1, 2, 1);
  insere_movimento(jogo, 2, 0, 1);
  insere_movimento(jogo, 2, 1, 1);
  insere_movimento(jogo, 2, 2, 2);
  REQUIRE(verifica_velha(jogo) == 0);


  inicia_jogo(jogo);
  insere_movimento(jogo, 0, 0, 2);  // 2 1 2
  insere_movimento(jogo, 0, 1, 1);  // 2 1 1
  insere_movimento(jogo, 0, 2, 2);  // 1 2 1
  insere_movimento(jogo, 1, 0, 2);
  insere_movimento(jogo, 1, 1, 1);
  insere_movimento(jogo, 1, 2, 1);
  insere_movimento(jogo, 2, 0, 1);
  insere_movimento(jogo, 2, 1, 2);
  insere_movimento(jogo, 2, 2, 1);
  REQUIRE(verifica_velha(jogo) == 0);
}

