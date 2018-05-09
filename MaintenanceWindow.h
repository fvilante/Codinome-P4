/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MaintenanceWindow.h
 * Author: Flavio
 *
 * Created on 21 de Abril de 2018, 11:43
 */

#ifndef MAINTENANCEWINDOW_H
#define MAINTENANCEWINDOW_H

#include "IReceiver.h"

//Classe para representar a janela de manutencao.
//Faz um wrapping do sinal da janela manut.
class MaintenanceWindow {

    IReceiver<bool>* signal; //sinal da janela de manutencao

public:
    
    enum class State : bool { CLOSED=false, OPEN=true };
    
    MaintenanceWindow() = delete;
    MaintenanceWindow(IReceiver<bool>& sensorSignal) : signal(&sensorSignal) { }
    MaintenanceWindow(const MaintenanceWindow& orig);
    virtual ~MaintenanceWindow();
    
    MaintenanceWindow::State getState() { 
        return ( signal->read() == true ) ? 
            MaintenanceWindow::State::OPEN : MaintenanceWindow::State::CLOSED; 
    }
    
    
};


#endif /* MAINTENANCEWINDOW_H */

