/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleTest.cpp
 * Author: Flavio
 * 
 * Created on 19 de Abril de 2018, 11:40
 */

#include "SimpleClass.h"

#include <vector>

#include <iostream>
void testFunction() {


    //int g_x_plus_1 = F::g_x + 1; // in this context, only the value of g_x is needed.
                                 // so it's OK without the definition of g_x

    std::vector<F>  vi;
    
    vi.push_back(F::Posicao_inicial);
    
    std::cout << "Mano Mano mané" << (int) F::Coordenada_da_gaveta_na_posicao_2; 
    
    //vi.push_back( F::g_x );      // Error, this is odr-used, push_back(const int & t) expect
                                 // a const lvalue, so it's definition must be present

}


SimpleClass::SimpleClass() {
}

SimpleClass::SimpleClass(const SimpleClass& orig) {
}

SimpleClass::~SimpleClass() {
}

