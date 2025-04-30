#include "romanos.hpp"

int romanos_para_decimal(char const * num_romano) {

    int resultado = 0;

    for (int i_char = 0; i_char < sizeof(num_romano); i_char++) {
        if (char(num_romano[i_char]) == int(*"I")) {
            resultado++;
        }
    }
    return resultado;
}
