/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Devices.h
 * Author: Flavio
 *
 * Created on 12 de Maio de 2018, 05:07
 */

#ifndef DEVICES_H
#define DEVICES_H

#include "IReceiver.h"
#include "Digital.h"
#include "Properties.h"
#include "DigitalReceiver.h"


#include <memory>
#include <type_traits>
#include <cassert>
#include <tuple>


// ***************************************************************************
//  HELPERs
// ***************************************************************************

//This Helper class 'holds' and 'implements' a IReceiver<Digital> and adds 
//'inversion of logic' behavior to it.
class Device_Base : IReceiver<Digital> {
public:
    
    Device_Base() = delete;
    Device_Base(std::shared_ptr<IReceiver<Digital>> inputSensor)
            : receiver_(inputSensor) { };            
    virtual ~Device_Base() = default;
            
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


//Base class to construct device messages
class DeviceMessage_Base {
public:
    DeviceMessage_Base() = delete;
    DeviceMessage_Base(Digital d, uint8_t state, std::string desc) 
        : d_(d), state_(state), stateDesc_(desc) { }
    DeviceMessage_Base(const DeviceMessage_Base& orig) = default;
    virtual ~DeviceMessage_Base() = default;

    Digital getDigital() { return d_; }    
    std::string getStateDescription() { return stateDesc_; }
protected:
    uint8_t getStateInteger() { return state_; }
        
private:
    Digital d_;
    uint8_t state_;
    std::string stateDesc_; //state description 
};


// ***************************************************************************
//  DEVICES and DEVICE MESSAGES
// ***************************************************************************

class DrawerMessage : public DeviceMessage_Base {
public:
    enum class State : uint8_t { Opened, Closed, Null };
    
    DrawerMessage() = delete;
    DrawerMessage(Digital d, State s, std::string desc) 
            : DeviceMessage_Base(d,static_cast<uint8_t>(s),desc) 
            { }
    DrawerMessage(const DrawerMessage& orig) = default;
    virtual ~DrawerMessage() = default;   
    
    State getState() { return static_cast<State>(getStateInteger()); }
    
};


//Classe para representar a gaveta.
//Esta classe faz um wrapping do sinal do sensor indutivo da gaveta
class Drawer : public Device_Base {

public:
    
    Drawer() = delete;    
    Drawer(std::shared_ptr<IReceiver<Digital>> sensor) 
        : Device_Base(sensor) { }
    Drawer(const Drawer& orig) = default;
    virtual ~Drawer() = default;
    
    //returns State message
    DrawerMessage getState() {         
        using State = DrawerMessage::State;        
        Digital d = readSignal();
        switch (d.getLevel()) {            
            case Level::Low :
                return DrawerMessage(d, State::Closed, "Gaveta Fechada");                
            case Level::High :                        
                return DrawerMessage(d, State::Opened, "Gaveta Aberta");
            case Level::None :                        
                return DrawerMessage(d, State::Null, "Gaveta em estado 'Null'");
        }
    }
    
protected:
    Digital readSignal() { return Device_Base::read(); }
    
private:
    
    //Coordenadas relativas da gaveta em relacao sistema absoluto da maquina
    PROPERTY(int, Coordenada_X_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Y_RelativaDaGaveta, 0);
    PROPERTY(int, Coordenada_Z_RelativaDaGaveta, 0);
    PROPERTY(bool, Inverter_Logica_Do_Sinal, false);
  
};


class MaintenanceWindowMessage : public DeviceMessage_Base {
public:
    enum class State : uint8_t { Opened, Closed, Null };
    
    MaintenanceWindowMessage() = delete;
    MaintenanceWindowMessage(Digital d, State s, std::string desc) 
            : DeviceMessage_Base(d,static_cast<uint8_t>(s),desc) 
            { }
    MaintenanceWindowMessage(const MaintenanceWindowMessage& orig) = default;
    virtual ~MaintenanceWindowMessage() = default;   
    
    State getState() { return static_cast<State>(getStateInteger()); }
    
};

//Classe para representar a janela de manutencao.
//Faz um wrapping do sinal da janela manut.
class MaintenanceWindow : public Device_Base {
    
public:
    
    MaintenanceWindow() = delete;
    MaintenanceWindow(std::shared_ptr<IReceiver<Digital>> sensor) 
        : Device_Base(sensor) { }
    MaintenanceWindow(const MaintenanceWindow& orig) = default;
    virtual ~MaintenanceWindow() = default;
    
    //returns State message
    MaintenanceWindowMessage getState() {         
        using State = MaintenanceWindowMessage::State;        
        Digital d = readSignal();
        switch (d.getLevel()) {            
            case Level::Low :
                return MaintenanceWindowMessage(d, State::Closed, "Janela de Manutencao Fechada");                
            case Level::High :                        
                return MaintenanceWindowMessage(d, State::Opened, "Janela de Manutencao Aberta");
            case Level::None :                        
                return MaintenanceWindowMessage(d, State::Null, "Janela de Manutencao em estado 'Null'");
        }
    }
 
protected:
    Digital readSignal() { return Device_Base::read(); }
    
private:
 
};


class EmergencyButtomMessage : public DeviceMessage_Base {
public:
    enum class State : uint8_t { Pressed, Not_Pressed, Null };
    
    EmergencyButtomMessage() = delete;
    EmergencyButtomMessage(Digital d, State s, std::string desc) 
            : DeviceMessage_Base(d,static_cast<uint8_t>(s),desc) 
            { }
    EmergencyButtomMessage(const EmergencyButtomMessage& orig) = default;
    virtual ~EmergencyButtomMessage() = default;   
    
    State getState() { return static_cast<State>(getStateInteger()); }
    
};

//Classe para representar botão de emergencia
class EmergencyButtom : public Device_Base {

public:
    
    EmergencyButtom() = delete;
    EmergencyButtom(std::shared_ptr<IReceiver<Digital>> sensor) 
        : Device_Base(sensor) { }
    EmergencyButtom(const EmergencyButtom& orig) = default;
    virtual ~EmergencyButtom() = default;
    
    //returns State message    
    EmergencyButtomMessage getState() {         
        using State = EmergencyButtomMessage::State;        
        Digital d = readSignal();
        switch (d.getLevel()) {            
            case Level::Low :
                return EmergencyButtomMessage(d, State::Not_Pressed, "Botão de Emergencia Não Pressionado");                
            case Level::High :                        
                return EmergencyButtomMessage(d, State::Pressed, "Botão de Emergencia Pressionado");
            case Level::None :                        
                return EmergencyButtomMessage(d, State::Null, "Botão de Emergencia em estado 'Null'");
        }
    }
    
protected:
    Digital readSignal() { return Device_Base::read(); }
    
private:
    
};




// ***************************************************************************
//  DEVICE FACTORIES
// ***************************************************************************


//Factory to a Drawer
std::shared_ptr<Drawer> 
createDrawer(std::shared_ptr<IReceiver<Digital>> sensor);

//Factory to a MaintenanceWindow
std::shared_ptr<MaintenanceWindow> 
createMaintenanceWindow(std::shared_ptr<IReceiver<Digital>> sensor); 

//Factory to a Emergency Buttom
std::shared_ptr<EmergencyButtom> 
createEmergencyButtom(std::shared_ptr<IReceiver<Digital>> sensor);


#endif /* DEVICES_H */
