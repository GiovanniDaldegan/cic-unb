#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[require]") {
   REQUIRE(romanos_para_decimal("I") == 1);
   REQUIRE(romanos_para_decimal("V") == 5);
   REQUIRE(romanos_para_decimal("X") == 10);
   REQUIRE(romanos_para_decimal("L") == 50);
   REQUIRE(romanos_para_decimal("C") == 100);
   REQUIRE(romanos_para_decimal("D") == 500);
   REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - numeros com mais de um algarismo", "[require]") {
	REQUIRE(romanos_para_decimal("II") == 2);
	REQUIRE(romanos_para_decimal("VII") == 7);
	REQUIRE(romanos_para_decimal("XVI") == 16);
	REQUIRE(romanos_para_decimal("CLX") == 160);
	REQUIRE(romanos_para_decimal("MD") == 1500);
	REQUIRE(romanos_para_decimal("MDCLXVI") == 1666);
}


TEST_CASE( "Numeros romanos - algarismos invalidos", "[romanos]" ) {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("#") == -1);
	REQUIRE(romanos_para_decimal("Í") == -1);
}

