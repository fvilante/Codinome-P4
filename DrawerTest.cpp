/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Drawer.h"
#include "InputSignalStub.h"
#include "Properties.h"

#include "catch.hpp"


TEST_CASE( "Drawer class Test", "[Drawer]" ) {

    //Arrange    
    bool initialValue = true; //valor inicial do sinal            
    DigitalInputSignalStub& stub = *( new DigitalInputSignalStub(initialValue) ); 
    //cria a gaveta
    Drawer gaveta = Drawer(stub, Drawer::Id::GAVETA1);

    SECTION("Testa metodo getId da gaveta") {
        
        Drawer::Id id = gaveta.getId();
        REQUIRE(id == Drawer::Id::GAVETA1);
        
    }

    SECTION("Testa variacao") {

        stub.put(false);
        REQUIRE(gaveta.getState() == Drawer::State::CLOSED);

        stub.put(true);
        REQUIRE(gaveta.getState() == Drawer::State::OPEN);
    }

    SECTION("Testa Propriedades") {

        Drawer m = Drawer(stub, Drawer::Id::GAVETA1);

        SECTION("Testa inicializacao das Propriedades") {
            TESTA_LER_PROPRIEDADE(Coordenada_X_RelativaDaGaveta, 0);
            TESTA_LER_PROPRIEDADE(Coordenada_Y_RelativaDaGaveta, 0);
            TESTA_LER_PROPRIEDADE(Coordenada_Z_RelativaDaGaveta, 0);
        }

        SECTION("Testa setters e getters das Propriedades com valores arbitrarios") {
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_X_RelativaDaGaveta, 1500);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_Y_RelativaDaGaveta, -1500);
            TESTA_GRAVAR_E_LER_PROPRIEDADE(Coordenada_Z_RelativaDaGaveta, 20);
        }

    }



};

