/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BarCodeValidationAlgorithm.h
 * Author: Flavio
 *
 * Created on 20 de Abril de 2018, 23:06
 */

#ifndef BARCODEVALIDATIONALGORITHM_H
#define BARCODEVALIDATIONALGORITHM_H


#include <vector>
#include <string>

//CLASSIC LEONI BAR CODE VALIDATION ALGOTIHM
//classic P4-Leoni Barcode Validation Algorithm
//it takes a string that can contains one or more
//valid or invalid barcodes, and returns a vector
//containing only the valid ones.
std::vector<std::string> 
BarCodeValidationAlgorithm_Classic(const std::string);


#endif /* BARCODEVALIDATIONALGORITHM_H */
