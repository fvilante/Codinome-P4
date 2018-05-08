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

#include "IInputSignal.h"

//Classe para representar botão de emergencia
class EmergencyButtom {

    IDigitalInputSignal* signal; //sinal do botao de emergencia

public:
    
    enum class State : bool { CLOSED=false, OPEN=true };
    
    EmergencyButtom() = delete;
    EmergencyButtom(IDigitalInputSignal& sensorSignal) : signal(&sensorSignal) { }
    EmergencyButtom(const EmergencyButtom& orig);
    virtual ~EmergencyButtom();
    
    EmergencyButtom::State getState() { 
        return ( signal->read() == true ) ? 
            EmergencyButtom::State::OPEN : EmergencyButtom::State::CLOSED; 
    }
    
    
};

#endif /* EMERGENCYBUTTOM_H */

