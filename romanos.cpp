#include "romanos.hpp"

int romanos_para_decimal(char const * num_romano) {

    int resultado = 0;
        // char* simbolos = "IVXLCDM";

    for (int i_char = 0; i_char < sizeof(num_romano); i_char++) {
        if (char(num_romano[i_char]) == int(*"I")) {
            resultado++;
        }
        else if (char(num_romano[i_char]) == int(*"V")) {
            resultado += 5;
        }
        else if (char(num_romano[i_char]) == int(*"X")) {
            resultado += 10;
        }
        else if (char(num_romano[i_char]) == int(*"L")) {
            resultado += 50;
        }
        else if (char(num_romano[i_char]) == int(*"C")) {
            resultado += 100;
        }
        else if (char(num_romano[i_char]) == int(*"D")) {
            resultado += 500;
        }
        else if (char(num_romano[i_char]) == int(*"M")) {
            resultado += 1000;
        }

    }
    return resultado;
}
