/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DigitalSignal.h
 * Author: Flavio
 *
 * Created on 7 de Maio de 2018, 11:23
 */

#ifndef DIGITALSIGNAL_H
#define DIGITALSIGNAL_H

#include "TimeStamp.h"

#include <stdint.h>


//Abstracao de um sinal digital
//-Pode ser nulo
//-Se for nulo deve-se ignorar o timestamp
class DigitalSignal {
    
public:
    
    enum class Level : uint8_t { Low=0, High=1, None=2 };
    
    //constructors (rule of 5)
    
    DigitalSignal() : level_(Level::None), timeStamp_(TimeStamp()) { };
    explicit DigitalSignal(Level e) : level_(e), timeStamp_(TimeStamp()) { };
    DigitalSignal(const DigitalSignal& other) 
        : level_(other.level_), timeStamp_(other.timeStamp_) { };
    DigitalSignal(DigitalSignal&& other)
        : level_(other.level_), timeStamp_(other.timeStamp_) 
        { 
            other.level_ = Level::None;
            //other.timeStamp_ = TimeStamp();
        }
    DigitalSignal& operator=(const DigitalSignal& other) {
        if (&other != this) {
            level_ = other.level_;
            timeStamp_ = other.timeStamp_;
        }
        return *this;
    }
    DigitalSignal& operator=(DigitalSignal&& other) {
        if (&other != this) {
            level_ = other.level_;
            timeStamp_ = other.timeStamp_;
            other.level_ = Level::None;
        }
        return *this;
    }
    virtual ~DigitalSignal() { }
    
    //other operators overloads
    
    bool operator==(const DigitalSignal& other) const {
        return (level_ == other.level_);
    }
    bool operator!=(const DigitalSignal& other) const {
        return (level_ != other.level_);
    }
    
    //common getters, setters and functions
    
    const Level getLevel() const { return level_; }
    bool isEmpty() const { return (level_ == Level::None) ? true : false; }
    

private:
    
    Level level_;
    TimeStamp timeStamp_;

};

#endif /* DIGITALSIGNAL_H */

