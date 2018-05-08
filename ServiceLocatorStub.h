/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServiceLocatorStub.h
 * Author: Flavio
 *
 * Created on 27 de Abril de 2018, 16:01
 */

#ifndef SERVICELOCATORSTUB_H
#define SERVICELOCATORSTUB_H

#include "Cabecote.h"
#include "BarCode.h"
#include "Matriz.h"
#include "Drawer.h"
#include "DrawerRepository.h"
#include "MatrizRepository.h"
#include "BarCodeQueue.h"
#include "CabecoteRepository.h"
#include "Receiver.h"
#include "IServiceLocator.h"
#include "ServiceLocatorBasic.h"


class StubServicesFactory {

protected:
    //Sinais das gavetas
    Receiver<bool> sensor_gaveta_1_ = Receiver<bool>(true);
    Receiver<bool> sensor_gaveta_2_ = Receiver<bool>(true);  
    
    //Matriz Repository
    std::vector<Matriz> matrizContainer_ = { Matriz(), Matriz(), Matriz() };
    MatrizRepository matrizRepo_ = MatrizRepository(matrizContainer_);
    
    //Drawer Repository
    std::vector<Drawer> drawerContainer_ = { 
        Drawer(sensor_gaveta_1_, Drawer::Id::GAVETA1), 
        Drawer(sensor_gaveta_2_, Drawer::Id::GAVETA2), 
    };    
    DrawerRepository drawerRepo_ = DrawerRepository(drawerContainer_);
    
    //BarCode Queue
    BarCodeQueue barCodeQueue_ = BarCodeQueue();
    
    //CabecoteRepository
    std::vector<Cabecote> cabecoteConteiner_ = {
        Cabecote(0,0,Cabecote::Id::CABECOTE_1, Cor::BRANCO),
        Cabecote(0,0,Cabecote::Id::CABECOTE_2, Cor::PRETO),
    };
    CabecoteRepository cabecoteRepo_ = CabecoteRepository(cabecoteConteiner_);
    
    //ServiceLocator
    ServiceLocatorBasic serviceLocator_ = 
            ServiceLocatorBasic(matrizRepo_, drawerRepo_, barCodeQueue_, cabecoteRepo_ );
            
    
public:

    StubServicesFactory() { };
    StubServicesFactory(const StubServicesFactory& orig);
    virtual ~StubServicesFactory() { };

};

class ServiceLocatorStub : public IServiceLocator, public StubServicesFactory {
    
public:    
    
    ServiceLocatorStub() { };
    ServiceLocatorStub(const ServiceLocatorStub& orig) = default;
    virtual ~ServiceLocatorStub() { };
    
    //Implements Interface
    MatrizRepository& getMatrizRepository() final { return matrizRepo_; }
    DrawerRepository& getDrawerRepository() final { return drawerRepo_; }
    BarCodeQueue& getBarCodeQueue() final { return barCodeQueue_; }
    CabecoteRepository& getCabecoteRepository() final { cabecoteRepo_; }
    
    //Emulation Services
    void setDrawerSensorLevel(Drawer::Id id, bool level) {
        switch (id) {            
            case Drawer::Id::GAVETA1 :
                sensor_gaveta_1_ = level;
                break;
            case Drawer::Id::GAVETA2 :
                sensor_gaveta_1_ = level;
                break;
        }
    } 
    void putBarCodeOnQueue(BarCode barCode) {
        getBarCodeQueue().pushBack(barCode);
    }
    
    
};



#endif /* SERVICELOCATORSTUB_H */

