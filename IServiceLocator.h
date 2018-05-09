/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IServiceLocator.h
 * Author: Flavio
 *
 * Created on 27 de Abril de 2018, 13:56
 */

#ifndef ISERVICELOCATOR_H
#define ISERVICELOCATOR_H

#include "MatrizRepository.h"
#include "DrawerRepository.h"
#include "BarCodeQueue.h"
#include "CabecoteRepository.h"

class IServiceLocator {

public:
    
    //INTERFACE
    
    //Setters
    /* I think setters are unnecessary at the interface, maybe eventually 
     * only implemented in derived classes. I commented this section while
     * we decide its real usefulness.
        virtual void setMatrizRepository(MatrizRepository& m)=0;
        virtual void setDrawerRepository(DrawerRepository& m)=0;
        virtual void setBarCodeQueue(BarCodeQueue& m)=0;
        virtual void setCabecoteRepository(CabecoteRepository& r)=0;
    */
    //Getters
        virtual MatrizRepository& getMatrizRepository()=0;
        virtual DrawerRepository& getDrawerRepository()=0;
        virtual BarCodeQueue& getBarCodeQueue()=0;
        virtual CabecoteRepository& getCabecoteRepository()=0;
    
        
    
};

#endif /* ISERVICELOCATOR_H */

