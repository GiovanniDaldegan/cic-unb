#define CATCH_CONFIG_MAIN
#include "romanos.hpp"
#include <iostream>

using namespace std;

int valor_alg(const char alg) {
	switch(alg) {
		case int(*"I"): return 1;
		case int(*"V"): return 5;
		case int(*"X"): return 10;
		case int(*"L"): return 50;
		case int(*"C"): return 100;
		case int(*"D"): return 500;
		case int(*"M"): return 1000;
		default:		return -1;
	}
}

int checa_negativo(const char* numero) {
	if (valor_alg(*numero) < valor_alg(*(numero + 1))) {
		return 1;
	}
	else {
		return 0;
	}
}

int romanos_para_decimal(const char * num_romano) {
    int resultado = 0;
	char alg_ultimo;
	int conta_rep = 0;

	int offset = 0;
	while (*(num_romano + offset) != '\0') {
		// checa se é um algarismo válido
		if (valor_alg(*(num_romano + offset)) == -1) {
			return -1;
		}

		// soma se for positivo, subtrai se for negativo
		if (checa_negativo(num_romano + offset)) {
			resultado -= valor_alg(*(num_romano + offset));
		}
		else {
			resultado += valor_alg(*(num_romano + offset));
		}

		// conta quantas vezes o algarismo se repete em bloco
		if (*(num_romano + offset) == alg_ultimo) {
			conta_rep++;
		}

		// se o algarismo for da forma 5 * (1 + 10 * x) e repetir, o número é inválido
		if ((valor_alg(alg_ultimo) * 10) % 50 == 0) {
			if (conta_rep > 0) {
				return -1;
			}
		}
		// se o algarismo for da forma 1 * (1 + 10 * x) e repetir 3 vezes, o número é inálido
		else if (conta_rep > 2) {
			return -1;
		}

		alg_ultimo = *(num_romano + offset);
		offset++;
	}

    return resultado;
}
