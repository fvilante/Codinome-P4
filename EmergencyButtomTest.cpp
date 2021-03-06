/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EmergencyButtom.h"
#include "InputSignalStub.h"

#include "catch.hpp"


    TEST_CASE( "EmergencyButtom class Test", "[EmergencyButtom]" ) {
        
        //Arrange
        
        bool initialValue = true;       
        DigitalInputSignalStub& stub = *(new DigitalInputSignalStub(initialValue)); 
        //cria a gaveta
        EmergencyButtom botaoDeEmergencia = EmergencyButtom(stub);

        SECTION("Testa variacao") {
            
            stub.put(false);
            REQUIRE(botaoDeEmergencia.getState() == EmergencyButtom::State::CLOSED);
            
            stub.put(true);
            REQUIRE(botaoDeEmergencia.getState() == EmergencyButtom::State::OPEN);
        }
        

    };
