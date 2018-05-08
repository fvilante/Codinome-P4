/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IInputSignal.h
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 18:02
 */

#ifndef IINPUTSIGNAL_H
#define IINPUTSIGNAL_H



//forward declaration
template <class T> class IInputSignal;

using IDigitalInputSignal = IInputSignal<bool>;

template <class T> 
class IInputSignal {
    
public:
    
    virtual T read() const =0;
    
};



#endif /* IINPUTSIGNAL_H */

