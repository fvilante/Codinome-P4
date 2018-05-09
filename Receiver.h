/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Receiver.h
 * Author: Flavio
 *
 * Created on 19 de Abril de 2018, 22:28
 */

#ifndef RECEIVER_H
#define RECEIVER_H

#include "IReceiver.h"


template <class T>
class Receiver : public IReceiver<T> {
    
    T signal_;

public:
    Receiver() = delete;
    Receiver(T initial_value) : signal_(initial_value) { }        
    Receiver(const Receiver& orig) = default;
    virtual ~Receiver(){ };

    //Interface implementation
    T read() const override { return signal_; }
    
    //puts a specified signal inside the stub.
    //this signal will only be read when client access read() method.
    void put(T signal) { signal_ = signal; }

};

#endif /* RECEIVER_H */

