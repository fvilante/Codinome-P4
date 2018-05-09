/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrizRepository.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 20:53
 */

#ifndef MATRIZREPOSITORY_H
#define MATRIZREPOSITORY_H

#include "Matriz.h"
#include "BarCode.h"

#include <vector>
#include <string>
#include <iostream>

class MatrizRepository {

    std::vector<Matriz> repository_;
    
public:
    MatrizRepository() = delete;
    MatrizRepository(const std::vector<Matriz> repositorio) : repository_(repositorio) { }
    MatrizRepository(const MatrizRepository& orig) = default; // not sure if i wanna delete this...
    virtual ~MatrizRepository();

    Matriz find(BarCode barCode) { 
        for (auto i : repository_) {
            if (i.getLeituraDoCodigoDeBarras() == barCode.getRawSignal()) 
                return i;
        }
        // else
        return Matriz();
    }
    

};

#endif /* MATRIZREPOSITORY_H */

