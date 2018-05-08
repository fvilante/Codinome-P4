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

class SimpleClass {
public:
    SimpleClass();
    SimpleClass(const SimpleClass& orig);
    virtual ~SimpleClass();
    
    int getInt() { return 666; } //The number of the best (Iron Maden '90s)
    
    
private:

};

#endif /* SIMPLECLASS_H */

