/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Devices.h"
#include "Receiver.h"
#include "Digital.h"
#include "Properties.h"


#include "catch.hpp"

#include <Memory>


TEST_CASE( "Drawer class Test", "[Drawer]" ) {

    //parameters    
    const auto level_ToClose = Digital(Level::Low);
    const auto level_ToOpen = Digital(Level::High);
    const auto level_Null = Digital(Level::None);
    
    //arrange
    auto sensor = createDigitalReceiver(level_ToClose);
    
    //cria a gaveta
    auto gaveta1 = createDrawer(sensor);
 
    
    SECTION("Testa variacao na entrada, checa saida") {

        sensor->put(level_ToClose);
        DrawerMessage m1 = gaveta1->getState();
        REQUIRE(m1.getState() == DrawerMessage::State::Closed);

        sensor->put(level_ToOpen);
        DrawerMessage m2 = gaveta1->getState();
        REQUIRE(m2.getState() == DrawerMessage::State::Opened);

    }
    

    SECTION("Testa Propriedades") {

        Drawer m = Drawer(sensor);

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


TEST_CASE( "MaintenanceWindow class Test", "[MaintenanceWindow]" ) {

    //parameters   
    const auto level_ToClose = Digital(Level::Low);
    const auto level_ToOpen = Digital(Level::High);
    const auto level_Null = Digital(Level::None);

    //create sensor
    auto sensor = createDigitalReceiver(level_ToClose);  
    
    //cria a gaveta
    auto janelaDeManutencao = createMaintenanceWindow(sensor);

    SECTION("Testa variacao na entrada, checa saida") {

        sensor->put(level_ToClose);
        MaintenanceWindowMessage m1 = janelaDeManutencao->getState();
        REQUIRE(m1.getState() == MaintenanceWindowMessage::State::Closed);

        sensor->put(level_ToOpen);
        MaintenanceWindowMessage m2 = janelaDeManutencao->getState();
        REQUIRE(m2.getState() == MaintenanceWindowMessage::State::Opened);

    }


};



TEST_CASE( "EmergencyButtom class Test", "[EmergencyButtom]" ) {

    //parameters   
    const auto level_ToNotPressed = Digital(Level::Low);
    const auto level_ToPressed = Digital(Level::High);
    const auto level_Null = Digital(Level::None);
    

    //create sensor
    auto sensor = createDigitalReceiver(level_ToNotPressed);
    
    //cria a gaveta
    auto botaoDeEmergencia = createEmergencyButtom(sensor);

    SECTION("Testa variacao") {
        
        sensor->put(level_ToNotPressed);
        EmergencyButtomMessage m1 = botaoDeEmergencia->getState();
        REQUIRE(m1.getState() == EmergencyButtomMessage::State::Not_Pressed);

        sensor->put(level_ToPressed);
        EmergencyButtomMessage m2 = botaoDeEmergencia->getState();
        REQUIRE(m2.getState() == EmergencyButtomMessage::State::Pressed);
    }


};