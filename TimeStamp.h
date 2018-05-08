/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeStamp.h
 * Author: Flavio
 *
 * Created on 7 de Maio de 2018, 11:35
 */

#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <chrono>

#include <string>


//#include "date.h" //third-party library
#include <iostream>
#include <ctime>


using duration_in_nanoseconds = std::chrono::nanoseconds;
using system_clock = std::chrono::system_clock;    
using TimePoint = std::chrono::time_point<system_clock, duration_in_nanoseconds>;


//em nanosegundos
class TimeStamp {

public:
    TimeStamp() { }
    TimeStamp(const TimeStamp& orig) { }
    virtual ~TimeStamp() { }
    
    std::chrono::nanoseconds getNanosecs() {
        using namespace std::chrono;
        system_clock::duration dtn = timePoint_.time_since_epoch();
        nanoseconds ms = duration_cast<nanoseconds>(dtn);
        return ms;
    }
    
    void debugPrint() {
        using namespace std::chrono;
        
        system_clock::duration dtn = timePoint_.time_since_epoch();
        
        std::time_t t = system_clock::to_time_t(timePoint_);
        nanoseconds ms = duration_cast<nanoseconds>(dtn);        
        std::cout << std::ctime(&t);
        std::cout << " us:(" << ms.count() << ")" << std::endl;
    }
    
    //TimePoint getTimeStamp() { return time
    

private:
    
    TimePoint timePoint_ = std::chrono::system_clock::now();
    

};

#endif /* TIMESTAMP_H */

