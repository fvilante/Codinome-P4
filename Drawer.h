/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drawer.h
 * Author: Flavio
 *
 * Created on 20 de Abril de 2018, 15:27
 */

#ifndef DRAWER_H
#define DRAWER_H

#include "IReceiver.h"
#include "Digital.h"
#include "Properties.h"
#include "DigitalReceiver.h"

#include <memory>
#include <type_traits>
#include <cassert>


// ***************************************************************************
//  HELPERs
// ***************************************************************************

//This Helper class 'holds' and 'implements' a IReceiver<Digital> and adds 
//'inversion of logic' behavior to it.
class DigitalReceiverHolder : IReceiver<Digital> {
public:
    
    DigitalReceiverHolder() = delete;
    DigitalReceiverHolder(std::shared_ptr<IReceiver<Digital>> inputSensor)
            : receiver_(inputSensor) { };            
    virtual ~DigitalReceiver_Base() = default;
            
    //Interface
    Digital read() const override final { return getSignal_UseInvertionCriteria(); }    
    //set/get Flag for logic inversion of the digital signal when read
    void setLogicInversionFlag(bool b) { hasToInvertLogic_ = b; }
    bool getLogicInversionFlag() const { return hasToInvertLogic_; }

protected:    
    Digital getSignal_UseInvertionCriteria() const {         
        return (hasToInvertLogic_ == true) ?
            (getSignal().invert()) : getSignal();
    }        
    Digital getSignal() const { return receiver_->read(); }    

private:
    std::shared_ptr<IReceiver<Digital>> receiver_;   
    bool hasToInvertLogic_ = false;
};




// ***************************************************************************
//  DEVICES 
// ***************************************************************************


//Classe para representar a gaveta.
//Esta classe faz um wrapping do sinal do sensor indutivo da gaveta
class Drawer {

public:
    
    Drawer() = delete;    
    Drawer(std::shared_ptr<IReceiver<Digital>> sensor) 
        : receiverHolder_(sensor) { }
    Drawer(const Drawer& orig) = default;
    virtual ~Drawer() = default;
    
    //States
    bool isClosed() { return (readSignal() == Level::Low) ? true : false; }
    bool isOpened() { 
        return ((readSignal() == Level::High) || (readSignal() == Level::None)) ? 
            true : false; 
    }
    //set/get Flag for logic inversion of the digital signal when read
    void setLogicInversionFlag(bool b) { receiverHolder_.setLogicInversionFlag(b); }
    bool getLogicInversionFlag() const { return receiverHolder_.getLogicInversionFlag(); }
    
protected:
    Digital readSignal() { return receiverHolder_.read(); }
    
private:
     
    DigitalReceiverHolder receiverHolder_;
    
    //Coordenadas relativas da gaveta em relacao sistema absoluto da maquina
    PROPERTY(int, Coordenada_X_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Y_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Z_RelativaDaGaveta, 0);
    PROPERTY(bool, Inverter_Logica_Do_Sinal, false);
  
};


// ***************************************************************************
//  DEVICE FACTORIES
// ***************************************************************************


//Helper function to factory a drawer object
std::shared_ptr<Drawer> 
createDrawer(std::shared_ptr<IReceiver<Digital>> sensor);


#endif /* DRAWER_H */

