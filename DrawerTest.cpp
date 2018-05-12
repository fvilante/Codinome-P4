/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Drawer.h"
#include "Receiver.h"
#include "Digital.h"
#include "Properties.h"


#include "catch.hpp"

#include <Memory>


TEST_CASE( "Drawer class Test", "[Drawer]" ) {

    //parameters   
    const auto level_ToClose = Digital(Level::Low);
    const auto level_ToOpen = Digital(Level::High);
    
    //arrange
    auto sensor1 = createDigitalReceiver(level_ToClose);
    
    //cria a gaveta
    auto gaveta1 = createDrawer(sensor1);

    SECTION("Testa abertura e fechamento do sinal da gaveta") {

        REQUIRE(gaveta1->getLogicInversionFlag()==false);
        
        sensor1->put( level_ToClose );
        REQUIRE(gaveta1->isClosed() == true);
        REQUIRE(gaveta1->isOpen() == false);


        sensor1->put( level_ToOpen );
        REQUIRE(gaveta1->isOpen() == true);
        REQUIRE(gaveta1->isClosed() == false);
    }
    
    SECTION("Testa inversao de logica da gaveta") {

        REQUIRE(gaveta1->getLogicInversionFlag()==false);
        gaveta1->setLogicInversionFlag(true);
        REQUIRE(gaveta1->getLogicInversionFlag()==true);
        
        sensor1->put( level_ToClose );
        REQUIRE(gaveta1->isClosed() == false);
        REQUIRE(gaveta1->isOpen() == true);

        sensor1->put( level_ToOpen );
        REQUIRE(gaveta1->isClosed() == true);
        REQUIRE(gaveta1->isOpen() == false);
    }
    

    SECTION("Testa Propriedades") {

        Drawer m = Drawer(sensor1);

        SECTION("Testa inicializacao das Propriedades") {
            TESTA_LER_PROPRIEDADE(Coordenada_X_RelativaDaGaveta, 0);
            TESTA_LER_PROPRIEDADE(Coordenada_Y_RelativaDaGaveta, 0);
            TESTA_LER_PROPRIEDADE(Coordenada_Z_RelativaDaGaveta, 0);
            TESTA_LER_PROPRIEDADE(Inverter_Logica_Do_Sinal, false);
        }

        SECTION("Testa setters e getters das Propriedades com valores arbitrarios") {
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_X_RelativaDaGaveta, 1500);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_Y_RelativaDaGaveta, -1500);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_Z_RelativaDaGaveta, 20);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Inverter_Logica_Do_Sinal, true);
        }

    }

};

