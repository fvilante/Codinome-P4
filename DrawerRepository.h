/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrawerRepository.h
 * Author: Flavio
 *
 * Created on 26 de Abril de 2018, 23:48
 */

#ifndef DRAWERREPOSITORY_H
#define DRAWERREPOSITORY_H

#include "Drawer.h"

#include <vector>

class DrawerRepository {

    std::vector<Drawer> repository_;
    
public:
    DrawerRepository() = delete;
    DrawerRepository(const DrawerRepository& orig) = default; // not sure if i wanna delete this...
    DrawerRepository(const std::vector<Drawer> repositorio) : repository_(repositorio) { }
    virtual ~DrawerRepository();

    Drawer Find(Drawer::Id id) { 
        for (Drawer i : repository_) {
            if (i.getId() == id) 
                return i;
        } 
        //Este trecho aqui é perigoso, pq se o cara der find em drawer nao listada
        //no repositorio (exemplo Drawer::Id::GAVETA_NULL) qual será a referencia 
        //retornada desta funcao ? #?# refatorar
    }
};

#endif /* DRAWERREPOSITORY_H */

