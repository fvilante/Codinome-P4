/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EmergencyButtom.h"
#include "Receiver.h"
#include "Digital.h"

#include "catch.hpp"

#include <memory>


TEST_CASE( "EmergencyButtom class Test", "[EmergencyButtom]" ) {

    //arrange   
    Digital level_low {Level::Low};
    Digital level_high {Level::High};

    //create sensor
    auto sensor = createDigitalReceiver(level_low);
    //cria a gaveta
    EmergencyButtom botaoDeEmergencia = EmergencyButtom(sensor);

    SECTION("Testa variacao") {

        sensor->put(level_low);
        REQUIRE(botaoDeEmergencia.getState() == EmergencyButtom::State::CLOSED);

        sensor->put(level_high);
        REQUIRE(botaoDeEmergencia.getState() == EmergencyButtom::State::OPEN);
    }


};
