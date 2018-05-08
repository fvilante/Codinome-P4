/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Cabecote.h"
#include "Properties.h"

#include "catch.hpp"


TEST_CASE("Cabecote Class Test", "[Cabecote]") {
    
   
    SECTION("Testa Construcao com parametros e getters") {

        int x = -100, y = +200;
        Cabecote::Id id = Cabecote::Id::CABECOTE_1;
        
        SECTION("Parametros de construcao arbitrarios 1") {        
            //arrange
            Cor cor = Cor::PRETO;            
            //act
            Cabecote cab = Cabecote(x,y,id, cor);
            //assert
            REQUIRE(cab.getX_Relativo_ao_Cabecote_Branco() == x);
            REQUIRE(cab.getY_Relativo_ao_Cabecote_Branco() == y);
            REQUIRE(cab.getCor() == cor);
            REQUIRE(cab.getId() == id);
        }
        
        SECTION("Testa o fato do cabecote branco ter posicao relativa x,y zero") {        
            //arrange
            Cor cor = Cor::BRANCO;            
            //act
            Cabecote cab = Cabecote(x,y,id,cor);
            //assert
            REQUIRE(cab.getX_Relativo_ao_Cabecote_Branco() == 0);
            REQUIRE(cab.getY_Relativo_ao_Cabecote_Branco() == 0);
            REQUIRE(cab.getCor() == cor);    
        }
        
    }
    
    
};

