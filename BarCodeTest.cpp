/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BarCode.h"

#include "catch.hpp"
#include <string>
#include <vector>

TEST_CASE( "BarCode class Test", "[BarCode]" ) {
    
        //arrange
        std::vector<std::string> testCases = {
            "10237401372", "0q987r0q87we", "-0q98r078r90", "pioasd", "oajsd",
            "aoisjdfoajsaoisdjfaosdfjs", "a", "0", "1000000000000000000000000",
            "oaisdfwsdjfoiajsdofiajsdofiasjdofiajsdofiajsdfoaisdfjoaisdjfoiasdjf"
        };

        SECTION("Testa construcao e getRawSogmal") {

            for (auto i : testCases) {
                //cria barcode
                auto b = BarCode(i);    
                REQUIRE(b.getRawSignal() == i);
        };
        
        SECTION("Testa operador==") {
          
            auto code1 = BarCode(testCases.at(0));
            auto code2 = BarCode(testCases.at(0));
            
            REQUIRE(code1 == code2);
            
        };
        
           
        
    
    }
};

