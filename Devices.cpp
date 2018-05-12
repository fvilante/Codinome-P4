/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Devices.cpp
 * Author: Flavio
 * 
 * Created on 12 de Maio de 2018, 05:07
 */

#include "Devices.h"



std::shared_ptr<Drawer> 
createDrawer(std::shared_ptr<IReceiver<Digital>> sensor) { 
    return std::make_shared< Drawer >(sensor);
}

std::shared_ptr<MaintenanceWindow> 
createMaintenanceWindow(std::shared_ptr<IReceiver<Digital>> sensor) { 
    return std::make_shared< MaintenanceWindow >(sensor);
}

std::shared_ptr<EmergencyButtom> 
createEmergencyButtom(std::shared_ptr<IReceiver<Digital>> sensor) { 
    return std::make_shared< EmergencyButtom >(sensor);
}
