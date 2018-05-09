/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JobProducer.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 02:07
 */

#ifndef JOBGENERATOR_H
#define JOBGENERATOR_H


#include "Drawer.h"
#include "BarCode.h"
#include "BarCodeQueue.h"
#include "Job.h"
#include "Matriz.h"
#include "IServiceLocator.h"
#include "Cabecote.h"
#include "CorDaTinta.h"

#include <memory>
#include <vector>


//Encapsulates pointers and abstracts class properties
//So sub-classe can focus only "Job" creation algorithm
class JobProducer_Base {

private:    
    IServiceLocator* serviceLocator_;

  
protected:
    
    JobProducer_Base() = delete;
    JobProducer_Base(IServiceLocator& s) : serviceLocator_(&s) { }
    JobProducer_Base(const JobProducer_Base& orig) = delete;
    virtual ~JobProducer_Base() = default;
    
    
    //****** Helper functions and Member encapsulation ******************************
    
    IServiceLocator& serviceLocator() { return *serviceLocator_; }
    
    Drawer gaveta_1() { return serviceLocator().getDrawerRepository().Find(Drawer::Id::GAVETA1); }
    Drawer gaveta_2() { return serviceLocator().getDrawerRepository().Find(Drawer::Id::GAVETA2); }   
    
    BarCode obtemBarCodeDaFila() { return serviceLocator().getBarCodeQueue().pullFront(); }
    bool temBarCodeNaFila() { return !serviceLocator().getBarCodeQueue().isEmpty(); }
    
    Cabecote::Id getCabecote(Matriz matriz) { 
        Cor cor = matriz.getCorDaTintaAImprimir();
        Cabecote& cab = serviceLocator().getCabecoteRepository().Find(cor);        
        return cab.getId();
    }
    
    Matriz getMatrizFromRepository(BarCode barcode) { return serviceLocator().getMatrizRepository().find(barcode); }
    
    Job criaJob(BarCode barcode, Drawer::Id gavetaId) { 
        Matriz matriz = getMatrizFromRepository(barcode);
        Cabecote::Id cabecoteId = getCabecote(matriz);
        return Job(barcode, gavetaId, matriz, cabecoteId);
    }
    
};

class JobProducer : private JobProducer_Base {

public:
    JobProducer() = delete;
    JobProducer(IServiceLocator& s) : JobProducer_Base(s) { }
    JobProducer(const JobProducer& orig) = delete;
    virtual ~JobProducer() = default;
    
    Job update() {       
  
        Job job = Job();
        
        bool soh_gaveta1_fechada = (gaveta_1().FECHADA() && gaveta_2().ABERTA());
        bool soh_gaveta2_fechada = (gaveta_2().FECHADA() && gaveta_1().ABERTA());
        
        if (soh_gaveta1_fechada && temBarCodeNaFila()) {            
            job = criaJob(obtemBarCodeDaFila(), gaveta_1().getId());            
        } else if (soh_gaveta1_fechada && temBarCodeNaFila()) {            
            job = criaJob(obtemBarCodeDaFila(), gaveta_2().getId());            
        }
                
        return job;
    }
};





#endif /* JOBGENERATOR_H */

