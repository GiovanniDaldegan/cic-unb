/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "velha.c"

TEST_CASE("Jogo vazio")
{
  int jogo[3][3] = {{0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}};

  REQUIRE(verifica_velha(jogo) == -1);
}
