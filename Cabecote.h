/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cabecote.h
 * Author: Flavio
 *
 * Created on 24 de Abril de 2018, 15:23
 */

#ifndef CABECOTE_H
#define CABECOTE_H

#include "Properties.h"

#include "CorDaTinta.h"

class Cabecote { 
    
public: enum class Id : int { CABECOTE_1, CABECOTE_2, CABECOTE_NULL };
    
private:
    PROPERTY(int, X_Relativo_ao_Cabecote_Branco, 0);
    PROPERTY(int, Y_Relativo_ao_Cabecote_Branco, 0);
    PROPERTY(Cor, Cor, Cor::PRETO);
    
    Id id_;
    
public:
    
    Cabecote() = delete;
    Cabecote(const Cabecote& orig) = default;
    virtual ~Cabecote();    
    Cabecote(int x, int y, Id id, Cor cor) 
        : 
        PROPERTY_DEF(Cor)(cor), 
        PROPERTY_DEF(X_Relativo_ao_Cabecote_Branco)(x), 
        id_(id),
        PROPERTY_DEF(Y_Relativo_ao_Cabecote_Branco)(y) 
        { 
            //Se cabecote for branco, o X e Y relativo a ele é zero
            if (PROPERTY_DEF(Cor) == Cor::BRANCO) { 
                PROPERTY_DEF(X_Relativo_ao_Cabecote_Branco) = 0; 
                PROPERTY_DEF(Y_Relativo_ao_Cabecote_Branco) = 0;
            }
    
        }
    
    Id getId() const { return id_; }


    
};

#endif /* CABECOTE_H */

