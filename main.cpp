/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 10:56
 */

#include <cstdlib>
#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   
    //Runs unit tests
    int result = Catch::Session().run( argc, argv );    
    
    
    return 0;
}

