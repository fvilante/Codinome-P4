/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleTest.h
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 11:40
 */

#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H


// ************** DEBUGING TEMPORARY **********************
#include <stdint.h>

enum class F : uint8_t { 
    Posicao_inicial, 
    Coordenada_da_gaveta_na_posicao_2 = 3
};

struct T {
   //const int g_x = 2;
   enum : uint8_t { 
       Posicao_inicial, 
       Coordenada_da_gaveta_na_posicao_2
   };
};

void testFunction();
// ************** 



class SimpleClass {
public:
    SimpleClass();
    SimpleClass(const SimpleClass& orig);
    virtual ~SimpleClass();
    
    int getInt() { return 666; } //The number of the best (Iron Maden '90s)
    
    
private:

};

#endif /* SIMPLECLASS_H */

