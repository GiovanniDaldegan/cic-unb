/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */


#include <stdlib.h>
#include "./velha.h"

int* conta_jogadas(int jogo[3][3]) {
  int* jogadas = (int*) calloc(3, sizeof(int));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // números de jogador inválidos
      if (jogo[i][j] < 0 || jogo[i][j] > 2) {
        jogadas[0] = -1;
        jogadas[1] = -1;
        jogadas[2] = -1;
        break;
      }

      jogadas[jogo[i][j]]++;
    }
  }

  return jogadas;
}

int vencedor_linhas(int jogo[3][3]) {
  /*
   * Matriz 2x3 que conta quantas linhas completas existem.
   * Nos índices [0][*], armazena valores 0 (linha incompleta) ou 1 (linha
   * completa), um pra cada linha.\n
   * Nos índices [1][*], armazena os números dos jogadores que preencheram as
   * linhas.
   */
  int cont_lin[2][3] = {{0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // checa repetições nas linhas
      if (jogo[i][j] == cont_lin[1][i]) {
        cont_lin[0][i]++;
      } else {
        cont_lin[0][i] = 0;
        cont_lin[1][i]= jogo[i][j];
      }
    }
  }

  int vitorias_linhas = 0;
  int vencedor = 0;

  for (int i = 0; i < 3; i++) {
    if (cont_lin[0][i] == 2) {
      vitorias_linhas++;
      vencedor = cont_lin[1][i];
    }
  }

  if (vitorias_linhas > 1)
    return -1;

  return vencedor;
}

int vencedor_colunas(int jogo[3][3]) {
  /*
   * Matriz 2x3 que conta quantas colunas completas existem.
   * Nos índices [0][*], armazena valores 0 (coluna incompleta) ou 1 (coluna
   * completa), um pra cada coluna.\n
   * Nos índices [1][*], armazena os números dos jogadores que preencheram as
   * colunas.
   */
  int cont_col[2][3] = {{0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // checa repetições nas colunas
      if (jogo[i][j] == cont_col[1][j]) {
        cont_col[0][j]++;
      } else {
        cont_col[0][j] = 0;
        cont_col[1][j] = jogo[i][j];
      }
    }
  }

  int vitorias_colunas = 0;
  int vencedor = 0;

  for (int i = 0; i < 3; i++) {
    if (cont_col[0][i] == 2) {
      vitorias_colunas++;
      vencedor = cont_col[1][i];
    }
  }

  if (vitorias_colunas > 1)
    return -1;

  return vencedor;
}

int vencedor_diagonais(int jogo[3][3]) {
  /*
   * Matriz 2x2 que conta quantas diagonais completas existem.
   * Nos índices [0][*], armazena valores 0 (diagonal incompleta) ou 1
   * (diagonal completa), um pra cada diagonal.\n
   * Nos índices [1][*], armazena o número do jogador que preencheu adiagonal.
   */
  int cont_diag[2][2] = {{0}};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // checa repetições na diagonal principal
      if (i == j) {
        if (jogo[i][j] == cont_diag[1][0]) {
          cont_diag[0][0]++;
        } else {
          cont_diag[0][0] = 0;
          cont_diag[1][0] = jogo[i][j];
        }
      }

      // checa repetições da diagonal secundária
      if (i + j == 2) {
        if (jogo[i][j] == cont_diag[1][1]) {
          cont_diag[0][1]++;
        } else {
          cont_diag[0][1] = 0;
          cont_diag[1][1] = jogo[i][j];
        }
      }
    }
  }

  // checa vitória na diagonal principal
  if (cont_diag[0][0] == 2 && cont_diag[1][0] != 0)
    return cont_diag[1][0];
  // checa vitória na diagonal secundária
  if (cont_diag[0][1] == 2 && cont_diag[1][1] != 0)
    return cont_diag[1][1];

  return 0;
}

int vencedor(int jogo[3][3]) {
  int v_l = vencedor_linhas(jogo);
  int v_c = vencedor_colunas(jogo);
  int v_d = vencedor_diagonais(jogo);

  if (v_l == -1 || v_c == -1 || v_d == -1)
    return -1;

  if (v_l != 0)
    return v_l;
  else if (v_c != 0)
    return v_c;

  return v_d;

  // arrays de checacem de vitória
  //  [0][*] contadores de repetição (1 por linha/coluna/diagonal)
  //  [1][*] número que se repete (1 por linha/coluna/diagonal)
  //  [*][0] linha/coluna 1 ou diagonal principal
  //  [*][1] linha/coluna 2 ou diagonal secundária
  //  [*][2] linha/coluna 3
}

int verifica_velha(int jogo[3][3]) {
  int* jogadas = conta_jogadas(jogo);

  // impossível: números de jogador inválidos
  if (jogadas[0] == -1 || jogadas[1] == -1 || jogadas[2] == -1)
    return -2;

  // impossível: número inválido de jogadas
  if (jogadas[2] > jogadas[1] || jogadas[1] > jogadas[2] + 1)
    return -2;

  int v = vencedor(jogo);

  // impossível: mais de uma vitória
  if (v == -1)
    return -2;
  // vencedor
  else if (v != 0)
    return v;
  // empate
  else if (jogadas[0] == 0)
    return 0;

  // jogo válido, indefinido
  return -1;
}

