/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Receiver.h"

#include <string>

#include "catch.hpp"

TEST_CASE("InputSignalStub class Test") {

    SECTION( "stub boleano") {
        
        //Arrange Parameters
        const int maxSignals = 6;
        using T = bool;
        T signals[maxSignals] = { 
            true, false , true, false, false, true
        };
        
        //Act, Assert            
        Receiver<T> stub = Receiver<T>(signals[0]);        
        for (int k=0; k<maxSignals;k++ ) {
            stub.put(signals[k]);
            REQUIRE( stub.read() == signals[k] );
        }
    }
    
    
    SECTION( "stub inteiro") {
        
        //Arrange Parameters
        const int maxSignals = 6;
        using T = bool;
        T signals[maxSignals] = { 
            10, 20, 30, 00, 10000, 2
        };
        
        //Act, Assert            
        Receiver<T> stub = Receiver<T>(signals[0]);        
        for (int k=0; k<maxSignals;k++ ) {
            stub.put(signals[k]);
            REQUIRE( stub.read() == signals[k] );
        }
    }
  
    
    SECTION( "stub string") {
        
        //Arrange Parameters
        const int maxSignals = 6;
        using T = std::string ;
        T signals[maxSignals] = { 
            "oi", "cachorro", "zé das couves", "joao", "melancia", "paralelepípeto"
        };
        
        //Act, Assert        
        Receiver<T> stub = Receiver<T>(signals[0]);        
        for (int k=0; k<maxSignals;k++ ) {
            stub.put(signals[k]);
            REQUIRE( stub.read() == signals[k] );
        };
    }
    
}