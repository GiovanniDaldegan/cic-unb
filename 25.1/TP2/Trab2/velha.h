/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */


#ifndef VELHA_H_
#define VELHA_H_

/**
 * Recebe uma matriz de jogo e retorna um array 1x3 com as contagens de 0, 1
 * e 2 presentes nele.
 * @param   jogo     Matriz 3x3.
 * @return  Array com as contages de 0, 1 e 2, uma em cada posição.
 */
int* conta_jogadas(int jogo[3][3]);

/**
 * Recebe uma matriz de jogo e retorna o número do jogador que preenche uma
 * linha completa.
 * @param  jogo  Matriz 3x3.
 * @return 0. Se não há linha completa, retorna 0.
 * @return 1 ou 2. Se há uma linha completa, retorna o número do jogador que a
 * preencheu.
 * @return -1. Se há mais de uma linha completa, retorna -1 (jogo impossível).
 */
int vencedor_linhas(int jogo[3][3]);

/**
 * Recebe uma matriz de jogo e retorna o número do jogador que preenche uma
 * coluna completa.
 * @param  jogo  Matriz 3x3.
 * @return 0. Se não há coluna completa, retorna 0.
 * @return 1 ou 2. Se há uma coluna completa, retorna o número do jogador que a
 * preencheu.
 * @return -1. Se há mais de uma coluna completa, retorna -1 (jogo impossível).
 */
int vencedor_colunas(int jogo[3][3]);

/**
 * Recebe uma matriz de jogo e retorna o número do jogador que preenche uma
 * diagonal completa.
 * @param  jogo  Matriz 3x3.
 * @return 0. Se não há diagonal completa, retorna 0.
 * @return 1 ou 2. Se há uma diagonal completa, retorna o número do jogador que
 * a preencheu.
 */
int vencedor_diagonais(int jogo[3][3]);

/**
 * Recebe uma matriz de jogo e retorna o vencedor do jogo.
 * @param  jogo  Matriz 3x3.
 * @return 0. Se não há vencedor, retorna 0.
 * @reutrn 1 ou 2. Se há vencedor, retorna o número dele.
 * @return -1. Se o jogo é impossível, retorna -1.
 */
int vencedor(int jogo[3][3]);

/**
 * Recebe uma matriz de jogo da velha e retorna o número do jogador que venceu
 * (1 ou 2), 0, -1 ou -2.
 * @param  jogo  Matriz 3x3.
 * @return 0. Se o jogo está empatado, retorna 0.
 * @return 1 ou 2. Se o jogo foi vencido, retorna o número do jogador que
 * venceu.
 * @return -1. Se o jogo está indefinido (válido, mas não terminado), retorna 0.
 * @return -2. Se o jogo não é válido (viola as regras), retorna -2.
 */
int verifica_velha(int[3][3]);

#endif  // VELHA_H_
