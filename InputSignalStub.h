/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InputSignalStub.h
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 22:28
 */

#ifndef INPUTSIGNALSTUB_H
#define INPUTSIGNALSTUB_H

#include "IInputSignal.h"

//forward declaration
template <class T> class InputSignalStub;

//Helper
using DigitalInputSignalStub = InputSignalStub<bool> ;



template <class T>
class InputSignalStub : public IInputSignal<T> {
    
    T signal_;

public:
    InputSignalStub() = delete;
    InputSignalStub(T initial_value) : signal_(initial_value) { }        
    InputSignalStub(const InputSignalStub& orig) = default;
    virtual ~InputSignalStub(){ };

    //Interface implementation
    T read() const override { return signal_; }
    
    //puts a specified signal inside the stub.
    //this signal will only be read when client access read() method.
    void put(T signal) { signal_ = signal; }

};

#endif /* INPUTSIGNALSTUB_H */

