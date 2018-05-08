/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DigitalSignal.h"

#include "catch.hpp"

TEST_CASE("DigitalSignal Class Test", "[DigitalSignal]") {
    
    using Level = DigitalSignal::Level;
    
    SECTION("default constructor is level none") {
        DigitalSignal d = DigitalSignal();
        REQUIRE(d.getLevel() == Level::None);
        REQUIRE(d.isEmpty() == true);
    }
    SECTION("Construct with a level") {
        SECTION("Level low") {
            DigitalSignal e = DigitalSignal(Level::Low);
            REQUIRE(e.getLevel() == Level::Low);
            REQUIRE(e.isEmpty() == false);
        }
        SECTION("Level high") {
            DigitalSignal e = DigitalSignal(Level::High);
            REQUIRE(e.getLevel() == Level::High);
            REQUIRE(e.isEmpty() == false);
        }
    }
}

