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

#include "Receiver.h"

#include <memory>

//Classe para representar a gaveta.
//Esta classe tambem faz um wrapping do sinal do sensor indutivo da gaveta
class Drawer {

public:
    
    enum class Id : int { GAVETA1, GAVETA2, GAVETA_NULL };
    
    enum class State : bool { CLOSED=false, OPEN=true };
    
    Drawer() = delete;    
    Drawer(std::shared_ptr<IReceiver<Digital>> sensorSignal, Id gavetaId ) 
        : signal(sensorSignal), gavetaId_(gavetaId) { } 
    Drawer(const Drawer& orig) = default;
    virtual ~Drawer() = default;
    
    Drawer::State getState() { 
        return ( signal->read() == Digital::Level::High ) ? 
            Drawer::State::OPEN : Drawer::State::CLOSED; 
    }
    
    Id getId() { return gavetaId_; } 
    
    //helpers
    bool FECHADA() { return (getState() == State::CLOSED) ? true : false; }
    bool ABERTA() { return (getState() == State::OPEN) ? true : false; }
    
    
private:
    std::shared_ptr<IReceiver<Digital>> signal; //sinal do sensor indutivo da gaveta
    Id gavetaId_;
    
    //Coordenadas relativas da gaveta em relacao sistema absoluto da maquina
    PROPERTY(int, Coordenada_X_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Y_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Z_RelativaDaGaveta, 0);
 
};

#endif /* DRAWER_H */

