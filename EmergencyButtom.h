/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmergencyButtom.h
 * Author: Flavio
 *
 * Created on 21 de Abril de 2018, 12:53
 */

#ifndef EMERGENCYBUTTOM_H
#define EMERGENCYBUTTOM_H

#include "IReceiver.h"
#include "Digital.h"

#include <memory>

//Classe para representar botão de emergencia
class EmergencyButtom {

public:
    
    enum class State : bool { CLOSED=false, OPEN=true };
    
    EmergencyButtom() = delete;
    EmergencyButtom(std::shared_ptr<IReceiver<Digital>> sensorSignal) : signal(sensorSignal) { }
    EmergencyButtom(const EmergencyButtom& orig) = default;
    virtual ~EmergencyButtom() = default;
    
    EmergencyButtom::State getState() { 
        return ( signal->read() == Level::High ) ? State::OPEN : State::CLOSED; 
    }
    
private:
    
    std::shared_ptr<IReceiver<Digital>> signal; //sinal do botao de emergencia
    
};

#endif /* EMERGENCYBUTTOM_H */

