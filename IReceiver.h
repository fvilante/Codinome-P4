/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IReceiver.h
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 18:02
 */

#ifndef IRECEIVER_H
#define IRECEIVER_H

#include "Digital.h"

//This interfaces sets the paradigm of "receiving an object"
template <class T> 
class IReceiver {
    
public:
    
    virtual T read() const =0;
    
};


#endif /* IRECEIVER_H */

