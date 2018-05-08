/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Matriz.h"
#include "BarCode.h"
#include "MatrizRepository.h"

#include "catch.hpp"

#include <vector>


TEST_CASE ("MatrizRepository Class Test", "[MatrizRepository]") {
    
    
    
    //criar vetor que sera injetado como repositorio de matrizes.    
    Matriz z[5];
    z[0].setLeituraDoCodigoDeBarras("Junior");
    z[1].setLeituraDoCodigoDeBarras("Alfredo");
    z[2].setLeituraDoCodigoDeBarras("Belchior");
    z[3].setLeituraDoCodigoDeBarras("Ze das couves");
    z[4].setLeituraDoCodigoDeBarras("Patria Amada");
    
    //std::cout << "[direto matriz]" <<  z4.getLeituraDoCodigoDeBarras() << "]" << std::endl;
    
    std::vector<Matriz> v;
    v.push_back(z[0]);
    v.push_back(z[1]);
    v.push_back(z[2]);
    v.push_back(z[3]);
    v.push_back(z[4]);
    
    //Injeta vetor no repositorio
    MatrizRepository m(v);
    
    SECTION ("Testa getMatriz()") {
        //arrange
        Matriz test = Matriz();
        CHECK( test.getLeituraDoCodigoDeBarras() == "");
        BarCode b = BarCode("Belchior");     
        //act
        test = m.find(b);
        //assert
        REQUIRE (test.getLeituraDoCodigoDeBarras() == "Belchior");
    }
    
    
    REQUIRE(1==1);
    
}

