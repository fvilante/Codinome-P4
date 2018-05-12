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

#include "Receiver.h"
#include "Digital.h"

#include <memory>
#include <winbase.h>

//Forward declaration
template <class T> class Receiver ;

//Helper function to factory a digital receiver object
std::shared_ptr<Receiver<Digital>> createDigitalReceiver(Digital initial_level);


//A generic 'receiver TEE' template with specialization for Digital case
template <class T>
class Receiver : public IReceiver<T> {

public:
    Receiver() = delete;
    Receiver(T initial_value) : signal_(initial_value) { }        
    Receiver(const Receiver& orig) = default;
    virtual ~Receiver() = default;

    //Interface implementation
    T read() const override { return signal_; }
    
    //puts a specified signal inside the TEE stub.
    //this signal will only be read when client access read() method.
    void put(T signal) { signal_ = signal; }

private:    
    T signal_;
    
};



#endif /* RECEIVER_H */

