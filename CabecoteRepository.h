/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CabecoteRepository.h
 * Author: Flavio
 *
 * Created on 24 de Abril de 2018, 21:48
 */

#ifndef CABECOTEREPOSITORY_H
#define CABECOTEREPOSITORY_H

#include "Cabecote.h"

#include <vector>

class CabecoteRepository {

    std::vector<Cabecote> repository_;
    
public:
    CabecoteRepository() = delete;
    CabecoteRepository(const std::vector<Cabecote> repositorio) : repository_(repositorio) { }
    CabecoteRepository(const CabecoteRepository& orig)= default; // not sure if i wanna delete this...
    virtual ~CabecoteRepository();

    Cabecote& Find(Cor cor) { 
        for (int k=0; k < repository_.size(); k++) {
            Cabecote* element = &(repository_.at(k));
            if (element->getCor() == cor) 
                return *element;
        }
    
    // if above code is executed, something wrong occured.
    return repository_.at(0); //any default value; ??###
    }

};

#endif /* CABECOTEREPOSITORY_H */

