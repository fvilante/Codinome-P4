/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MaintenanceWindow.h"
#include "Receiver.h"
#include "Digital.h"

#include "catch.hpp"

#include <memory>

TEST_CASE( "MaintenanceWindow class Test", "[MaintenanceWindow]" ) {

    //arrange   
    Digital level_low {Level::Low};
    Digital level_high {Level::High};

    //create sensor
    auto sensor = createDigitalReceiver(level_low);  
    
    //cria a gaveta
    MaintenanceWindow janelaDeManutencao = MaintenanceWindow(sensor);

    SECTION("Testa variacao") {

        sensor->put(level_low);
        REQUIRE(janelaDeManutencao.getState() == MaintenanceWindow::State::CLOSED);

        sensor->put(level_high);
        REQUIRE(janelaDeManutencao.getState() == MaintenanceWindow::State::OPEN);
    }


};