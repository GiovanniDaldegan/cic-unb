/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */

#define CATCH_CONFIG_MAIN
#include "../232002520_Giovanni/romanos.hpp"

int valor_alg(const char alg) {
  switch (alg) {
    case *"I": return 1;
    case *"V": return 5;
    case *"X": return 10;
    case *"L": return 50;
    case *"C": return 100;
    case *"D": return 500;
    case *"M": return 1000;
    default:   return -1;
  }
}

// checa se o algarismo precede outro maior que ele
int checa_negativo(const char* numero) {
  if (valor_alg(*numero) < valor_alg(*(numero + 1))) {
    return 1;
  } else {
    return 0;
  }
}

// checa se o algarismo é metade de X, C ou M
int checa_metade(const char alg) {
  switch (valor_alg(alg)) {
    case 5:
    case 50:
    case 500:
      return 1;

    default:
      return 0;
  }
}

int romanos_para_decimal(const char * num_romano) {
  int resultado = 0;
  char algarismo, alg_ultimo = '\0';

  int offset = 0, conta_rep = 0;
  while (*(num_romano + offset) != '\0') {
    algarismo = *(num_romano + offset);

    // checa se o primeiro algarismo é válido
    if (valor_alg(algarismo) == -1) {
      return -1;
    }

    resultado += (1 - 2 * checa_negativo(num_romano + offset))
                  * valor_alg(algarismo);

    // conta quantas vezes o algarismo se repete consecutivamente
    if (algarismo == alg_ultimo) {
      conta_rep++;
    } else {
      conta_rep = 0;
    }

    if (checa_metade(algarismo)) {                  // se for V, L ou D
      if (conta_rep > 0) {
        return -1;
      }
      if (checa_negativo(num_romano + offset)) {
        return -1;
      }
    } else {                                        // se for I, X, C ou M
      if (checa_negativo(num_romano + offset)) {
        if (conta_rep > 0) {
          return -1;
        }
        if (10 < valor_alg(*(num_romano + offset + 1)) / valor_alg(algarismo)) {
          return -1;
        }
      }
      if (conta_rep > 2) {
        return -1;
      }
    }

    alg_ultimo = algarismo;
    offset++;
  }

  return resultado;
}
