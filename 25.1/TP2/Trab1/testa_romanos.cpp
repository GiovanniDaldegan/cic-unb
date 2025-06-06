/*
 * Copyright 2025 Giovanni Daldegan. Nenhum direito reservado :)
 */

#define CATCH_CONFIG_MAIN
#include "../232002520_Giovanni/catch.hpp"
#include "../232002520_Giovanni/romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos",
          "[valor_alg]") {
  REQUIRE(romanos_para_decimal("I") == 1);
  REQUIRE(romanos_para_decimal("V") == 5);
  REQUIRE(romanos_para_decimal("X") == 10);
  REQUIRE(romanos_para_decimal("L") == 50);
  REQUIRE(romanos_para_decimal("C") == 100);
  REQUIRE(romanos_para_decimal("D") == 500);
  REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - numeros com mais de um algarismo",
          "[valor_alg]") {
  REQUIRE(romanos_para_decimal("II") == 2);
  REQUIRE(romanos_para_decimal("VII") == 7);
  REQUIRE(romanos_para_decimal("XVI") == 16);
  REQUIRE(romanos_para_decimal("CLX") == 160);
  REQUIRE(romanos_para_decimal("MD") == 1500);
  REQUIRE(romanos_para_decimal("MDCLXVI") == 1666);
  REQUIRE(romanos_para_decimal("MMM") == 3000);
  REQUIRE(romanos_para_decimal("MMMDCCCLXXXVIII") == 3888);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[valor_alg]" ) {
  REQUIRE(romanos_para_decimal("G") == -1);
  REQUIRE(romanos_para_decimal("i") == -1);
  REQUIRE(romanos_para_decimal("#") == -1);
  REQUIRE(romanos_para_decimal("�") == -1);
}

TEST_CASE("Numeros romanos - numero invalido de algarismos repetidos",
          "[valor_alg][rep_limite]") {
  REQUIRE(romanos_para_decimal("IIII") == -1);
  REQUIRE(romanos_para_decimal("VVVI") == -1);
  REQUIRE(romanos_para_decimal("XXXX") == -1);
  REQUIRE(romanos_para_decimal("LL") == -1);
  REQUIRE(romanos_para_decimal("CCCC") == -1);
  REQUIRE(romanos_para_decimal("DD") == -1);
}


TEST_CASE("Numeros romanos - algarismos negativos",
          "[valor_alg][negativo]") {
  REQUIRE(romanos_para_decimal("IV") == 4);
  REQUIRE(romanos_para_decimal("IX") == 9);
  REQUIRE(romanos_para_decimal("XL") == 40);
  REQUIRE(romanos_para_decimal("XLIV") == 44);
  REQUIRE(romanos_para_decimal("XCIX") == 99);
  REQUIRE(romanos_para_decimal("CMXCIX") == 999);
  REQUIRE(romanos_para_decimal("CDXCIV") == 494);
}

TEST_CASE("Numeros romanos - algarismo negativo invalido",
          "[valor_alg][negativo]") {
  REQUIRE(romanos_para_decimal("VX") == -1);
  REQUIRE(romanos_para_decimal("IC") == -1);
  REQUIRE(romanos_para_decimal("ID") == -1);
  REQUIRE(romanos_para_decimal("IM") == -1);
  REQUIRE(romanos_para_decimal("VD") == -1);
  REQUIRE(romanos_para_decimal("XM") == -1);
  REQUIRE(romanos_para_decimal("LC") == -1);
}

TEST_CASE("Numeros romanos - numero invalido de algarismos negativos",
          "[valor_alg][rep_limite][negativo]") {
  REQUIRE(romanos_para_decimal("IIV") == -1);
  REQUIRE(romanos_para_decimal("XXL") == -1);
  REQUIRE(romanos_para_decimal("XXC") == -1);
  REQUIRE(romanos_para_decimal("CCM") == -1);
}
