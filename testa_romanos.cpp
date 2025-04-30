#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("N�meros romanos - algarismos �nicos", "[romanos]") {
   REQUIRE(romanos_para_decimal("I") == 1);
   REQUIRE(romanos_para_decimal("V") == 5);
   REQUIRE(romanos_para_decimal("X") == 10);
   REQUIRE(romanos_para_decimal("L") == 50);
   REQUIRE(romanos_para_decimal("C") == 100);
   REQUIRE(romanos_para_decimal("D") == 500);
   REQUIRE(romanos_para_decimal("M") == 1000);
}

/*
TEST_CASE( "Numeros romanos - algarismos inv�lidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    
    REQUIRE( romanos_para_decimal("i") == -1 );
    
}
 */
