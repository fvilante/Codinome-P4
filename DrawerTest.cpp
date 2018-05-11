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

    //arrange   
    auto level_low = Digital(Level::Low);
    auto level_high = Digital(Level::High);
    
    //create sensor
    auto sensor1 = createDigitalReceiver(level_low);
    
    //cria a gaveta
    auto gaveta1 = createDrawer(sensor1, Drawer::Id::GAVETA1);

    SECTION("Testa metodo getId da gaveta") {
        
        Drawer::Id id = gaveta1->getId();
        REQUIRE(id == Drawer::Id::GAVETA1);
        
    }

    SECTION("Testa variacao") {

        sensor1->put( level_low );
        REQUIRE(gaveta1->getState() == Drawer::State::CLOSED);

        sensor1->put( level_high );
        REQUIRE(gaveta1->getState() == Drawer::State::OPEN);
    }

    SECTION("Testa Propriedades") {

        Drawer m = Drawer(sensor1, Drawer::Id::GAVETA1);

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

