/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "ServiceLocatorBasic.h"

#include "catch.hpp"

#include "MatrizRepository.h"
#include "CabecoteRepository.h"
#include "Drawer.h"
#include "BarCodeQueue.h"

#include "Matriz.h"
#include "IInputSignal.h"
#include "InputSignalStub.h"

#include "ServiceLocatorStub.h"
#include "ServiceLocatorBasic.h"

#include <vector>


TEST_CASE("ServiceLocatorBasic Class Test", "[ServiceLocatorBasic") {
    
    ServiceLocatorStub stub = ServiceLocatorStub();
    
    //act   
    ServiceLocatorBasic serviceLocatorBasic = ServiceLocatorBasic(
            stub.getMatrizRepository(), 
            stub.getDrawerRepository(),
            stub.getBarCodeQueue(), 
            stub.getCabecoteRepository()
            );
    
    //assert
    
    //serviceLocatorBasic.printQueue();
    
    REQUIRE(&serviceLocatorBasic.getMatrizRepository() == &stub.getMatrizRepository());   
    REQUIRE(&serviceLocatorBasic.getDrawerRepository() == &stub.getDrawerRepository());
    REQUIRE(&serviceLocatorBasic.getBarCodeQueue() == &stub.getBarCodeQueue());
    REQUIRE(&serviceLocatorBasic.getCabecoteRepository() == &stub.getCabecoteRepository());
    

    
}