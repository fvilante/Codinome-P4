/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Receiver.h"

//Helper function to factory a digital receiver object
std::shared_ptr<Receiver<Digital>> createDigitalReceiver(Digital initial_level) {    
    return std::make_shared< Receiver<Digital> >(initial_level);
}
