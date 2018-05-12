/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Digital.h
 * Author: Flavio
 *
 * Created on 7 de Maio de 2018, 11:23
 */

#ifndef DIGITAL_H
#define DIGITAL_H

#include "TimeStamp.h"

#include <stdint.h>



//Abstracao de um sinal digital
//-Pode ser nulo
//-Se for nulo deve-se ignorar o timestamp
class Digital {
    
public:
    
    enum class Level : uint8_t { Low=0, High=1, None=2 };
    
    //constructors (rule of 5)
    
    Digital() : level_(Level::None), timeStamp_(TimeStamp()) { };
    explicit Digital(Level e) : level_(e), timeStamp_(TimeStamp()) { };
    Digital(const Digital& other) 
        : level_(other.level_), timeStamp_(other.timeStamp_) { };
    Digital(Digital&& other)
        : level_(other.level_), timeStamp_(other.timeStamp_) 
        { 
            other.level_ = Level::None;
            //other.timeStamp_ = TimeStamp();
        }
    Digital& operator=(const Digital& other) {
        if (&other != this) {
            level_ = other.level_;
            timeStamp_ = other.timeStamp_;
        }
        return *this;
    }
    Digital& operator=(Digital&& other) {
        if (&other != this) {
            level_ = other.level_;
            timeStamp_ = other.timeStamp_;
            other.level_ = Level::None;
        }
        return *this;
    }
    virtual ~Digital() { }
    
    //other operators overloads
    
    bool operator==(const Digital& other) const {
        return (level_ == other.level_);
    }
    bool operator!=(const Digital& other) const {
        return (level_ != other.level_);
    }    
    bool operator==(const Digital::Level& other) const {
        return (level_ == other);
    }
    bool operator!=(const Digital::Level& other) const {
        return (level_ != other);
    }
    
    //invert its own 'level logic' if possible, and returns
    //a copy object with the new state.
    Digital invert() {
        switch (level_) {
            case Level::High :
                level_ = Level::Low;
                break;
            case Level::Low :
                level_ = Level::High;
                break;
            case Level::None :
                level_= Level::None;
                break;
            default:
                //throw a error; (???)
                level_ = Level::None;
                break;
        }
        
        return Digital(level_);
    } 
    
    //common getters, setters and functions
    
    const Level getLevel() const { return level_; }
    bool isEmpty() const { return (level_ == Level::None) ? true : false; }
    

private:
    
    Level level_;
    TimeStamp timeStamp_;

};



//Helper 'using' expression to improve (???) readability
using Level = Digital::Level;


#endif /* DIGITAL_H */

