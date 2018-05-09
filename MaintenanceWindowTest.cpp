/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "MaintenanceWindow.h"
#include "Receiver.h"

#include "catch.hpp"


    TEST_CASE( "MaintenanceWindow class Test", "[MaintenanceWindow]" ) {
        
        //Arrange        
        bool initialValue = true; //valor inicial do sinal                
        Receiver<bool>& stub = *( new Receiver<bool>(initialValue) );         
        //cria a gaveta
        MaintenanceWindow janelaDeManutencao = MaintenanceWindow(stub);

        SECTION("Testa variacao") {
            
            stub.put(false);
            REQUIRE(janelaDeManutencao.getState() == MaintenanceWindow::State::CLOSED);
            
            stub.put(true);
            REQUIRE(janelaDeManutencao.getState() == MaintenanceWindow::State::OPEN);
        }
        

    };