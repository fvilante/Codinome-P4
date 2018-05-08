/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarCode.h
 * Author: Flavio
 *
 * Created on 20 de Abril de 2018, 17:43
 */

#ifndef BARCODE_H
#define BARCODE_H

#include <string>

class BarCode {

    std::string rawSignal;
    
public:
    BarCode() : rawSignal("") { } ;// Not deleted to experiment as Null Object Pattern = delete;
    BarCode(std::string rawSignal_) : rawSignal(rawSignal_) { }
    BarCode(const BarCode& orig) = default;
    virtual ~BarCode() = default;
    
    std::string getRawSignal() const { return rawSignal; }
    
    bool operator==(const BarCode& other) const {
        return (other.getRawSignal() == this->getRawSignal()) ;
    }
    
    
};

#endif /* BARCODE_H */

