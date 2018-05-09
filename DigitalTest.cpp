/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Digital.h"

#include "catch.hpp"

TEST_CASE("DigitalSignal Class Test", "[DigitalSignal]") {
    
    using Level = Digital::Level;
    
    SECTION("default constructor is level none") {
        Digital d = Digital();
        REQUIRE(d.getLevel() == Level::None);
        REQUIRE(d.isEmpty() == true);
    }
    SECTION("Construct with a level") {
        SECTION("Level low") {
            Digital e = Digital(Level::Low);
            REQUIRE(e.getLevel() == Level::Low);
            REQUIRE(e.isEmpty() == false);
        }
        SECTION("Level high") {
            Digital e = Digital(Level::High);
            REQUIRE(e.getLevel() == Level::High);
            REQUIRE(e.isEmpty() == false);
        }
    }
}

