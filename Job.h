/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Job.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 03:07
 */

#ifndef JOB_H
#define JOB_H

#include "BarCode.h"
#include "Drawer.h"
#include "Matriz.h"
#include "Cabecote.h"


class Job {

    BarCode barCode_;
    Drawer::Id gavetaId_ = Drawer::Id::GAVETA_NULL;
    Matriz matriz_;
    Cabecote::Id cabecoteId_ = Cabecote::Id::CABECOTE_NULL;
    
    
    
public:
    Job() { };
    Job(BarCode b, Drawer::Id g, Matriz m, Cabecote::Id c ) 
        :  
        barCode_(b),
        gavetaId_(g),         
        matriz_(m),
        cabecoteId_(c)
        { }

    Job(const Job& orig);
    virtual ~Job();
    
    //HELPERS
    //Esta funcao nao é muito boa, pois se o cara esquecer de usa-la
    //ele pode tentar fazer get nos ponteiros que apontam pra nullptr
    //e isto nao é uma boa. Refatorar!
    bool isEmpty() { 
        return ( (cabecoteId_ == Cabecote::Id::CABECOTE_NULL) || 
                (gavetaId_ == Drawer::Id::GAVETA_NULL) ) ? true : false;
    }
    
    //PROPERTIES
    Matriz getMatriz() { return matriz_; }
    Drawer::Id getDrawerId() { return gavetaId_; }
    Cabecote::Id getCabecoteId() { return cabecoteId_; } 
    BarCode getBarCode() { return barCode_; }
    
    
    

};

#endif /* JOB_H */

