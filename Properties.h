/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: Flavio
 *
 * Created on 23 de Abril de 2018, 19:40
 */

#ifndef UTILS_H
#define UTILS_H

#define PROPERTY(type, name, inicial_value) \
private: type _##name = inicial_value; \
public: \
void set##name(const type var) \
{\
        _##name = var;\
}\
\
type get##name() const \
{\
        return _##name; \
}

#define PROPERTY_DEF(name) _##name



#define TESTA_LER_PROPRIEDADE(nome, valor) REQUIRE(m.get##nome() == valor)
#define TESTA_GRAVAR_PROPRIEDADE(nome, valor) m.set##nome(valor)
#define TESTA_GRAVAR_E_LER_PROPRIEDADE(nome, valor) TESTA_GRAVAR_PROPRIEDADE(nome, valor) ; TESTA_LER_PROPRIEDADE(nome, valor)



#endif /* UTILS_H */

