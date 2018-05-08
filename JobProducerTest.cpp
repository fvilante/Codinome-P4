/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "JobProducer.h"

#include "Job.h"


#include "Cabecote.h"
#include "BarCode.h"
#include "Matriz.h"
#include "Drawer.h"
#include "DrawerRepository.h"
#include "MatrizRepository.h"
#include "BarCodeQueue.h"
#include "CabecoteRepository.h"
#include "InputSignalStub.h"
#include "IServiceLocator.h"
#include "ServiceLocatorStub.h"

#include "catch.hpp"

#include <vector>



TEST_CASE("Job Producer Test") {
    
    //Arrange 
    //Create services
    ServiceLocatorStub& serviceLocator = *( new ServiceLocatorStub() );
    JobProducer& jobProducer = *( new JobProducer(serviceLocator) );
    Job j = Job();
    REQUIRE( j.isEmpty() == true);
    
    SECTION("Testa JobProducer contra a sinal vazio") {
        //Verifica se o produtor de jobs gera um Job vazio caso os criterios de criacao
        //de job nao sejam atendidos
    
        j = jobProducer.update();
        REQUIRE( j.isEmpty() == true);
    }
    
    SECTION("Testa se JobProducer responde a um sinal basico de producao") {
        //act
        //Movimenta sinais de entrada de modo a demandar uma criacao de job.
        serviceLocator.setDrawerSensorLevel(Drawer::Id::GAVETA1, false);
        serviceLocator.putBarCodeOnQueue(BarCode("Ola Mundo"));

        //assert
        //verifica se o produtor de jobs gerou o Job, e se gerou corretamente.
        j = jobProducer.update();
        REQUIRE( j.isEmpty() == false);
    }
/*
    SECTION("Se so tiver barcode (sem sinal de gaveta), produz job vazio") {
        //serviceLocator.setDrawerSensorLevel(Drawer::Id::GAVETA1, false);
        
        REQUIRE( j.isEmpty() == false);
        serviceLocator.putBarCodeOnQueue(BarCode("Ola Mundo"));
        j = jobProducer.update();
        REQUIRE( j.isEmpty() == false);
    }
    
    SECTION("Faz um teste mais elaborado no Job que esta sendo devolvido pelo Producer") {
        serviceLocator.setDrawerSensorLevel(Drawer::Id::GAVETA1, false);
        serviceLocator.putBarCodeOnQueue(BarCode("Ola Mundo"));

        
    }
    
*/
}
 