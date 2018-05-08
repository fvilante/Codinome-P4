/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SimpleClass.h"

#include "catch.hpp"

    
    TEST_CASE( "Numero de retorno está ok", "[SimpleTest]" ) {
        
        //arrange: 
        SimpleClass obj = SimpleClass();
        //act
        int a = obj.getInt();
        //assert
        REQUIRE( a == 666 );
        
    }