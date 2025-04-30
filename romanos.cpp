#define CATCH_CONFIG_MAIN
#include "romanos.hpp"
// #include <iostream>

// using namespace std;

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

// checa se o algarismo precede outro maior que ele
int checa_negativo(const char* numero) {
	if (valor_alg(*numero) < valor_alg(*(numero + 1))) {
		return 1;
	}
	else {
		return 0;
	}
}

// checa se o algarismo é metade de X, C ou M
int checa_metade(const char alg) {
	if ((valor_alg(alg) * 10) % 50 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int romanos_para_decimal(const char * num_romano) {
    int resultado = 0;
	char algarismo, alg_ultimo;

	int offset = 0, conta_rep = 0;
	while (*(num_romano + offset) != '\0') {
		algarismo = *(num_romano + offset);

		// checa se o primeiro algarismo é válido
		if (valor_alg(algarismo) == -1) {
			return -1;
		}

		resultado += (1 - 2 * checa_negativo(num_romano + offset)) * valor_alg(algarismo);

		// conta quantas vezes o algarismo se repete consecutivamente
		if (algarismo == alg_ultimo) {
			conta_rep++;
		}

		
		// se o algarismo for metade de X, C ou M e repetir, o número é inválido
		if (checa_metade(algarismo)) {
			if (conta_rep > 0) {
				return -1;
			}
		}
		// se o algarismo for I, X, C ou M e repetir 3 vezes, o número é inálido
		if (conta_rep > 2) {
			return -1;
		}

		alg_ultimo = algarismo;
		offset++;
	}

    return resultado;
}
