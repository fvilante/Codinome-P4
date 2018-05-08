/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarCodeReader.h
 * Author: Flavio
 *
 * Created on 20 de Abril de 2018, 17:16
 */

#ifndef BARCODEREADER_H
#define BARCODEREADER_H


#include "IInputSignal.h"
#include "BarCode.h"
#include "BarCodeValidationAlgorithm.h"

#include <string>
#include <vector>



//Classe traduz a leitura do codigo de barras da camada fisico
//para a camada de negócios.
class BarCodeReader {
    
    IInputSignal<std::string>* signal; //informacao do barcode
    
public:
    
    BarCodeReader() = delete;
    BarCodeReader(IInputSignal<std::string>& barCodeSignal_) : signal(&barCodeSignal_) { }
    BarCodeReader(const BarCodeReader& orig);
    virtual ~BarCodeReader();

    std::string getCode() const { 
        return signal->read();         
    } 
    
    BarCode getBarCode() const { 
        std::vector<std::string> validatedList = 
                BarCodeValidationAlgorithm_Classic(signal->read());
        
        std::string s = validatedList.at(0);
        
        return BarCode(s);         
    } 
    
    std::vector<BarCode> getBarCodeList() const {
        return std::vector<BarCode>();
    }
    
};





#endif /* BARCODEREADER_H */

