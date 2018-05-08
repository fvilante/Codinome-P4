/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServiceLocator.h
 * Author: Flavio
 *
 * Created on 24 de Abril de 2018, 19:54
 */

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H


#include "BarCodeQueue.h"
#include "JobQueue.h"
#include "MatrizRepository.h"
#include "CabecoteRepository.h"
#include "DrawerRepository.h"
#include "IServiceLocator.h"


//Uma versao classica do Service Locator onde todos os servicos sao injetados
//no objeto.
class ServiceLocatorBasic : public IServiceLocator {

    MatrizRepository* matrizRepository_;
    DrawerRepository* gavetaRepository_;
    BarCodeQueue* barCodeQueue_;
    CabecoteRepository* cabecoteRepository_;
    
public:
    ServiceLocatorBasic() { } //deletar no futuro= delete;
    ServiceLocatorBasic(MatrizRepository& m, DrawerRepository& g, BarCodeQueue& b, CabecoteRepository& c)
        :
        matrizRepository_(&m),
        gavetaRepository_(&g),
        barCodeQueue_(&b),
        cabecoteRepository_(&c)
        { /*std::cout << "construtor chega como:" << b;*/ }
    ServiceLocatorBasic(const ServiceLocatorBasic& orig) {
        matrizRepository_ = orig.matrizRepository_;
        gavetaRepository_ = orig.gavetaRepository_;
        barCodeQueue_ = orig.barCodeQueue_;
        cabecoteRepository_ = orig.cabecoteRepository_;
    }
    virtual ~ServiceLocatorBasic() = default;
    
    //Setters
        void setMatrizRepository(MatrizRepository& m) { matrizRepository_ = &m; }
        void setDrawerRepository(DrawerRepository& m) { gavetaRepository_ = &m; }
        void setBarCodeQueue(BarCodeQueue& m) { barCodeQueue_ = &m; }
        void setCabecoteRepository(CabecoteRepository& r) { cabecoteRepository_ = &r; }
    //Getters
        virtual MatrizRepository& getMatrizRepository() final { return *matrizRepository_; }
        virtual DrawerRepository& getDrawerRepository() final { return *gavetaRepository_; }
        virtual BarCodeQueue& getBarCodeQueue() final { return *barCodeQueue_; }
        virtual CabecoteRepository& getCabecoteRepository() final { return *cabecoteRepository_; }

};

#endif /* SERVICELOCATOR_H */

